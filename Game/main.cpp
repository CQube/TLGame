#include <irrlicht/irrlicht.h>
#include <irrlicht/driverChoice.h>
#include "MyEventReceiver.h"

using namespace irr;
using namespace io;
using namespace core;
using namespace video;
using namespace gui;
using namespace scene;

enum
{
	ID_IsNotPickable = 0,                                                
	IDFlag_IsPickable = 1 << 0,
	IDFlag_IsHighlightable = 1 << 1
};

const f32 MOVEMENT_SPEED = 5.f;

void moveCameraControl();
void oMove (IAnimatedMeshSceneNode *obj, f32 x, f32 y, f32 z)
{
	vector3df move;
	matrix4 matrix;

	move = vector3df(x, y, z);

	matrix.setRotationDegrees(obj -> getRotation());
	matrix.transformVect(move);

	obj -> setPosition(obj -> getPosition() + move);
}

void Turn (IAnimatedMeshSceneNode *obj, f32 x, f32 y, f32 z)
{
	obj -> setRotation(obj -> getRotation() + vector3df(x, y, z));
}
void SidneyMove(irr::scene::IAnimatedMeshSceneNode *node_sydney, MyEventReceiver *receiver)
{
	core::vector3df nodePosition_sydney = node_sydney->getPosition();

	if(receiver->IsKeyDown(irr::KEY_KEY_W)){
		oMove(node_sydney, MOVEMENT_SPEED, 0, 0);
	}

	if(receiver->IsKeyDown(irr::KEY_KEY_S)){
		oMove(node_sydney, -1 * MOVEMENT_SPEED, 0, 0);
	}
	        
	if(receiver->IsKeyDown(irr::KEY_KEY_D)){
		//Turn(node_sydney, 0, 5, 0);
		oMove(node_sydney, 0, 0, -1 * MOVEMENT_SPEED / 3 * 2);
	}
		
	if(receiver->IsKeyDown(irr::KEY_KEY_A)){
		//Turn(node_sydney, 0, 0, 0);
		oMove(node_sydney, 0, 0, MOVEMENT_SPEED / 3 * 2);
	}

	if(receiver->IsKeyDown(irr::KEY_KEY_V)){
		//Turn(node_sydney, 0, 5, 0);
		oMove(node_sydney, 0, 10, 0);
	}
}

void create3rdPersonCamera(IrrlichtDevice *device, irr::scene::IAnimatedMeshSceneNode *node_sydney, float &zdirection, float &direction)
{
	core::position2d<f32> cursorPos = device->getCursorControl()->getRelativePosition();
	scene::ICameraSceneNode* camera = device->getSceneManager()->getActiveCamera();
	core::vector3df cameraPos = camera->getAbsolutePosition();
	
	float change_x = ( cursorPos.X - 0.5 ) * 256.0f;
	float change_y = ( cursorPos.Y - 0.5 ) * 256.0f;
	direction += change_x;
	zdirection -= change_y;
	if( zdirection < -90 )
		zdirection = -90;
	else
		if( zdirection > 90 )
			zdirection = 90;
	device->getCursorControl()->setPosition( 0.5f, 0.5f );
	
	core::vector3df playerPos = node_sydney->getPosition();
	
	float xf = playerPos.X - cos( direction * core::PI / 180.0f ) * 64.0f;
	float yf = playerPos.Y - sin( zdirection * core::PI / 180.0f ) * 64.0f;
	float zf = playerPos.Z + sin( direction * core::PI / 180.0f ) * 64.0f;
	
	camera->setPosition( core::vector3df( xf, yf, zf ) );
	camera->setTarget( core::vector3df( playerPos.X, playerPos.Y+25.0f, playerPos.Z ) );
	node_sydney->setRotation( core::vector3df( 0, direction, 0 ) );
}

int main()
{	
	MyEventReceiver receiver;
	
	IrrlichtDevice* device =
		createDevice(EDT_OPENGL, core::dimension2d<u32>(640, 480),
			     16, false, false, false, &receiver);
	
	if (device == 0)
		return 1;
	
	video::IVideoDriver* driver = device->getVideoDriver();
	scene::ISceneManager* smgr = device->getSceneManager();

//   MAP LOAD	
/*	device->getFileSystem()->addFileArchive("pictures/map-20kdm2.pk3");  
	scene::IAnimatedMesh* q3level_mesh = smgr->getMesh("20kdm2.bsp");
	scene::IMeshSceneNode* node_map = 0;
	

	if (q3level_mesh)
		node_map = smgr->addOctreeSceneNode(q3level_mesh->getMesh(0), 0, IDFlag_IsPickable);
	scene::ITriangleSelector* selector = 0;
	
	if (node_map)
	{
		node_map->setPosition(core::vector3df(-1350,-130,-1400));
		
		selector = smgr->createOctreeTriangleSelector(
			node_map->getMesh(), node_map, 128);
		node_map->setTriangleSelector(selector);
	}
*/

	scene::ICameraSceneNode* camera = smgr->addCameraSceneNode(0, core::vector3df(-50.0f,50.0f,0.0f) ,
								   core::vector3df(0.0f,0.0f,0.0f), -1);
	
//Создание объектов
	ITerrainSceneNode *terrain = smgr->addTerrainSceneNode(
		"../media/terrain-heightmap.bmp",
		0,                    //родитель
		-1,                   //ID
		vector3df(0, 0, 0),   //позиция
		vector3df(0, 0, 0),   //поворот
		vector3df(40, 2, 40), //масштаб
		SColor(255, 255, 255, 255),//цвета вершин
		5,                    //максимум LOD
		ETPS_17,              //размер патча
		4);                   //коэфф. размытия
	terrain->setMaterialTexture(0 , driver->getTexture("../media/terrain-texture.jpg"));
	terrain->setMaterialTexture(1 , driver->getTexture("../media/detailmap3.jpg"));
	terrain->setMaterialType(EMT_DETAIL_MAP);
	terrain->scaleTexture(10.0f, 20.0f); 
	

	//create triangle selector for the terrain
	ITriangleSelector *selector = smgr->createTerrainTriangleSelector(terrain, 0);
	terrain->setTriangleSelector(selector);
	
	IMetaTriangleSelector *meta;
	meta = smgr->createMetaTriangleSelector();
	meta->addTriangleSelector(selector);
		
	ISceneNodeAnimator *anim =
		smgr->createCollisionResponseAnimator(meta, camera, vector3df (60, 100, 60),
						      vector3df (0, -10, 0), vector3df (0, 0, 0)); 
		
	selector -> drop();
	camera -> addAnimator(anim);
	anim -> drop();
	

	//lighting
	ILightSceneNode * lamp = smgr->addLightSceneNode(0, vector3df(0, 100, 0),
							 SColorf(0.8f, 0.8f, 0.6f));
	lamp -> setRadius(400);
	lamp -> setParent(camera);
	

	//create skybox and skydome
	driver -> setTextureCreationFlag(ETCF_CREATE_MIP_MAPS, false);

	ISceneNode *skybox = smgr->addSkyBoxSceneNode(
		driver->getTexture("../media/irrlicht2_up.jpg"),
		driver->getTexture("../media/irrlicht2_dn.jpg"),
		driver->getTexture("../media/irrlicht2_lf.jpg"),
		driver->getTexture("../media/irrlicht2_rt.jpg"),
		driver->getTexture("../media/irrlicht2_ft.jpg"),
		driver->getTexture("../media/irrlicht2_bk.jpg"));

	ISceneNode *skydome = smgr -> addSkyDomeSceneNode(driver -> getTexture("../media/skydome.jpg"), 16, 8, 0.95f, 2.0f);

	driver -> setTextureCreationFlag(ETCF_CREATE_MIP_MAPS, true);

	
//////////////////////////Создание модели, которой и будет осуществляться управление
	irr::scene::IAnimatedMesh *mesh_sydney = smgr->getMesh("../media/sydney.md2");
	
	if(!mesh_sydney)
	{
		device->drop();
		return 1;
	}
	irr::scene::IAnimatedMeshSceneNode *node_sydney = smgr->addAnimatedMeshSceneNode(mesh_sydney,
											 0, IDFlag_IsPickable);
	
	if(node_sydney)
	{
		node_sydney->setMaterialFlag(video::EMF_LIGHTING, false);
		node_sydney->setMD2Animation(scene::EMAT_STAND);
		node_sydney->setPosition(core::vector3df(180, 200, 0));
		node_sydney->setScale(core::vector3df(1.5f));
		node_sydney->setMaterialTexture(0, driver->getTexture("../media/sydney.bmp"));
	}

///////////////////////////////////////////////////////Cтолкнование для модели
	if (selector)
	{
		scene::ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(
			selector, node_sydney, core::vector3df(30,50,30),
			core::vector3df(0,-10,0), core::vector3df(0,0,0));
		selector->drop();
		node_sydney->addAnimator(anim);
		anim->drop(); 
	}

///////////////////////////////////////////////////////Скрыть курсор
	 
	device->getCursorControl()->setVisible(false);
	
//	scene::IAnimatedMeshSceneNode* node = 0;
//	video::SMaterial material;
//	material.Wireframe = true;	
//////////////////////////////////////////////////////////////////////Игровой цикл

	
	// This is the movemen speed in units per second.
	
	float direction = 0;
	float zdirection = 0;

	
	while(device->run())
	if (device->isWindowActive())
	{
		SidneyMove(node_sydney, &receiver);
		create3rdPersonCamera(device, node_sydney, zdirection, direction);

		driver->beginScene(true, true, video::SColor(255,113,113,133));
		smgr->drawAll();
	       	device->getGUIEnvironment()->drawAll(); // draw the gui environment (the logo)

		driver->endScene();
	        
	}
	
	device->drop();
	
	return 0;
}
