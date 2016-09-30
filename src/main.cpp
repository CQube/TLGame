#include <irrlicht/irrlicht.h>
#include <irrlicht/driverChoice.h>
#include "MyEventReceiver.h"
#include "Camera.hpp"
#include "Character.hpp"
#include "typedefs.hpp"
#include "Level.hpp"
using namespace tl;
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

ITriangleSelector* addAll(IrrlichtDevice *device);
ITerrainSceneNode* addTerrain(IrrlichtDevice* device);
const f32 MOVEMENT_SPEED = 5.f;
void oMove (AnimNode *obj, f32 x, f32 y, f32 z);
void Turn (AnimNode *obj, f32 x, f32 y, f32 z);
void SidneyMove(AnimNode *node_sydney, MyEventReceiver *receiver);
void addSkyBox(IrrlichtDevice* device);
void addSkyDome(IrrlichtDevice* device);
void addLightning(ISceneManager *smgr, ICameraSceneNode* SCamera);

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

//	Level *level = new Level(device);                 // class
//	ITriangleSelector *selector = level->loadLevel();
	ITriangleSelector *selector = addAll(device);     // function
 	
	Character *Sydney = new Character(device);
	AnimNode *node_sydney = Sydney->createCharacter("../media/sydney.md2", "../media/sydney.bmp", vector3df(180, 200, 0) );
	node_sydney->setScale(core::vector3df(1.5f));
	node_sydney->setMD2Animation(scene::EMAT_STAND);

	//Collisions
	if (selector)
	{
		scene::ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(
			selector, node_sydney, core::vector3df(30,50,30),
			core::vector3df(0,-10,0), core::vector3df(0,0,0));
		selector->drop();
		node_sydney->addAnimator(anim);
		anim->drop(); 
	}

	Character *Ninja = new Character(device);
       	AnimNode *node_ninja = Ninja->createCharacter("../media/ninja.b3d", vector3df(3071, 400, 1970), selector);

	Character *Dwarf = new Character(device);
        AnimNode *node_dwarf = Dwarf->createCharacter("../media/dwarf.x", vector3df(2760, 480, 3705), selector);
	node_dwarf->setRotation(vector3df(0, 20, 0));
	 
	device->getCursorControl()->setVisible(false);
	
//	scene::IAnimatedMeshSceneNode* node = 0;
//	video::SMaterial material;
//	material.Wireframe = true;

	Camera* camera = new Camera(device);
	camera->setFocusMesh(node_sydney);
	
	while(device->run())
	if (device->isWindowActive())
	{
		SidneyMove(node_sydney, &receiver);
		if(receiver.IsKeyDown(irr::KEY_KEY_Q)){
			vector3df pos_node = node_sydney->getPosition();
			std::cout << pos_node.X<<" " << pos_node.Y<<" " << pos_node.Z << std::endl;
		}
		
		camera->update();
		
		driver->beginScene(true, true, video::SColor(255,113,113,133));
		smgr->drawAll();
	       	device->getGUIEnvironment()->drawAll(); // draw the gui environment (the logo)

		driver->endScene();
	        
	}
	
	
	device->drop();
	
	return 0;
}

void oMove (AnimNode *obj, f32 x, f32 y, f32 z)
{
	vector3df move;
	matrix4 matrix;

	move = vector3df(x, y, z);

	matrix.setRotationDegrees(obj -> getRotation());
	matrix.transformVect(move);

	obj -> setPosition(obj -> getPosition() + move);
}

void Turn (AnimNode *obj, f32 x, f32 y, f32 z)
{
	obj -> setRotation(obj -> getRotation() + vector3df(x, y, z));
}

void SidneyMove(AnimNode *node_sydney, MyEventReceiver *receiver)
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




ITerrainSceneNode* addTerrain(IrrlichtDevice* device)
{
	ISceneManager *smgr = device->getSceneManager();
	IVideoDriver *driver = device->getVideoDriver();
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
	
	return terrain;
}

void addLightning(ISceneManager *smgr, ICameraSceneNode* SCamera)
{
	//Lighting	
	ILightSceneNode * lamp = smgr->addLightSceneNode(0, vector3df(0, 100, 0),
							 SColorf(0.8f, 0.8f, 0.6f));
	lamp -> setRadius(400);
	lamp -> setParent(SCamera);      
}


void addSkyBox(IrrlichtDevice* device)
{
	ISceneManager *smgr = device->getSceneManager();
	IVideoDriver *driver = device->getVideoDriver();
	
	ISceneNode *skybox = smgr->addSkyBoxSceneNode(
		driver->getTexture("../media/irrlicht2_up.jpg"),
		driver->getTexture("../media/irrlicht2_dn.jpg"),
		driver->getTexture("../media/irrlicht2_lf.jpg"),
		driver->getTexture("../media/irrlicht2_rt.jpg"),
		driver->getTexture("../media/irrlicht2_ft.jpg"),
		driver->getTexture("../media/irrlicht2_bk.jpg"));
}

void addSkyDome(IrrlichtDevice* device)
{
	ISceneManager *smgr = device->getSceneManager();
	IVideoDriver *driver = device->getVideoDriver();

	ISceneNode *skydome = smgr->addSkyDomeSceneNode(driver -> getTexture("../media/skydome.jpg"), 16, 8, 0.95f, 2.0f);

}

ITriangleSelector* addAll(IrrlichtDevice *device)
{
	ISceneManager *smgr = device->getSceneManager();
	IVideoDriver *driver = device->getVideoDriver();
	
	scene::ICameraSceneNode* SCamera = smgr->addCameraSceneNode(0, core::vector3df(-50.0f,50.0f,0.0f) ,
								   core::vector3df(0.0f,0.0f,0.0f), -1);
	
//Создание объектов //terrain начало
	//Create triangle selector for the terrain
	ITerrainSceneNode *terrain = addTerrain(device);
	
	ITriangleSelector *selector = smgr->createTerrainTriangleSelector(terrain, 0);
	terrain->setTriangleSelector(selector);
	
	IMetaTriangleSelector *meta;
	meta = smgr->createMetaTriangleSelector();
	meta->addTriangleSelector(selector);
		
	ISceneNodeAnimator *anim =
		smgr->createCollisionResponseAnimator(meta, SCamera, vector3df (60, 100, 60),
						      vector3df (0, -10, 0), vector3df (0, 0, 0)); 
		
	selector -> drop();
	SCamera -> addAnimator(anim);
	anim -> drop();
	
	addLightning(smgr, SCamera);		     
	driver -> setTextureCreationFlag(ETCF_CREATE_MIP_MAPS, false);
	

	//Create skybox and skydome
	addSkyBox(device);
	addSkyDome(device);

	driver -> setTextureCreationFlag(ETCF_CREATE_MIP_MAPS, true);
	return selector;
}
