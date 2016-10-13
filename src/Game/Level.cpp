#include "Level.hpp"

Level::Level(irr::IrrlichtDevice *_device)
{
	device = _device;
	driver = device->getVideoDriver();
	smgr = device->getSceneManager();
	meta = smgr->createMetaTriangleSelector();
	SCamera = NULL;
	skydome = NULL;
	skybox = NULL;
	lamp = NULL;
	selector = NULL;
	meta = NULL;
	anim = NULL;
	terrain = NULL;
	receiver = (EventReceiver *)device->getEventReceiver();
}

void Level::addTerrainSceneNode()
{
	terrain = smgr->addTerrainSceneNode(
		media_folder + "terrain-heightmap.bmp",
		0,                    //родитель
		-1,                   //ID
		irr::core::vector3df(0, 0, 0),   //позиция
		irr::core::vector3df(0, 0, 0),   //поворот
		irr::core::vector3df(40, 2, 40), //масштаб
		irr::video::SColor(255, 255, 255, 255),//цвета вершин
		5,                    //максимум LOD
		irr::scene::ETPS_17,              //размер патча
		4);                   //коэфф. размытия
	terrain->setMaterialTexture(0 , driver->getTexture(media_folder + "terrain-texture.jpg"));
	terrain->setMaterialTexture(1 , driver->getTexture(media_folder + "detailmap3.jpg"));
	terrain->setMaterialType(irr::video::EMT_DETAIL_MAP);
	terrain->scaleTexture(10.0f, 20.0f);

	selector = smgr->createTerrainTriangleSelector(terrain, 0);
	terrain->setTriangleSelector(selector);
}


void Level::addLightning() //надо указательно на smgr
{
       	//Lighting
	lamp = smgr->addLightSceneNode(0, irr::core::vector3df(0, 100, 0),
				       irr::video::SColorf(0.8f, 0.8f, 0.6f));
	lamp -> setRadius(400);
	lamp -> setParent(SCamera);      

}

void Level::addSkyBox()
{
	skybox = smgr->addSkyBoxSceneNode( Up, Down, Left, Right, Forward, Back );
}

//////////////////////////
////  LOAD
//////////////////////////
/*void Level::loadTerrainTextures()
{
	terrain_texture1 = driver->getTexture(media_folder + "terrain-texture.jpg");
	terrain_texture2 = driver->getTexture(media_folder + "detailmap3.jpg");
}
*/

void Level::loadSkyBoxTextures()
{
	Up      = driver->getTexture( media_folder + "irrlicht2_up.jpg" );
	Down    = driver->getTexture( media_folder + "irrlicht2_dn.jpg" );
	Left    = driver->getTexture( media_folder + "irrlicht2_lf.jpg" );
	Right   = driver->getTexture( media_folder + "irrlicht2_rt.jpg" );
	Forward = driver->getTexture( media_folder + "irrlicht2_ft.jpg" );
	Back    = driver->getTexture( media_folder + "irrlicht2_bk.jpg" );	
}

void Level::loadSkyDomeTextures()
{
	skydome_texture = driver->getTexture( media_folder + "skydome.jpg");
}

//////////////////////////end loads

void Level::addSkyDome()
{
	skydome = smgr->addSkyDomeSceneNode( skydome_texture, 16, 8, 0.95f, 2.0f);
}

void Level::loadMainHero()
{
	MainHero_mesh = smgr->getMesh(media_folder +"sydney.md2");
	MainHero_texture = driver->getTexture(media_folder +"sydney.bmp");
}

void Level::addMainHero()
{
	sydney = new MainHero(device, MainHero_mesh, MainHero_texture, vector3df(180, 200, 0));
	AnimNode *node_sydney = sydney->getAnimNode();
	node_sydney->setScale(core::vector3df(1.5f));
	node_sydney->setMD2Animation(scene::EMAT_STAND);

	sydney->addTrSelector(selector);
}

void Level::loadCharacters()
{
	ninja_mesh = smgr->getMesh(media_folder + "ninja.b3d");
	dwarf_mesh = smgr->getMesh(media_folder + "dwarf.x");
}

void Level::addCharacters()
{
        ninja = new Character(device, ninja_mesh, vector3df(3071, 400, 1970), selector);
//        AnimNode *node_ninja = ninja->getAnimNode();
	
	dwarf = new Character(device, dwarf_mesh, vector3df(2760, 480, 3705), selector);
        AnimNode *node_dwarf = dwarf->getAnimNode();
	node_dwarf->setRotation(vector3df(0, 20, 0));
}

void Level::loadLevel()
{
	SCamera = smgr->addCameraSceneNode(0, irr::core::vector3df(-50.0f,50.0f,0.0f) ,
					   irr::core::vector3df(0.0f,0.0f,0.0f), -1);
	loadMainHero();
	loadCharacters();
	addTerrainSceneNode();
	addMainHero();
//	addCharacters();
	
//load
	loadSkyBoxTextures();
	loadSkyDomeTextures();
	
	driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, true);
	camera = new Camera(device);
	camera->setFocusMesh(sydney->getAnimNode());        
}

irr::scene::ITriangleSelector *Level::getTrSelector()
{
	return selector;
}

void Level::run()
{	 
        camera->update();
// add'ы
	addSkyBox();
	addSkyDome();
	addLightning();
	addCharacters();
	sydney->Move(receiver);
		
	driver->beginScene(true, true, video::SColor(255,113,113,133));
	smgr->drawAll();
	device->getGUIEnvironment()->drawAll();
	
	driver->endScene();
	remove();
}

void Level::remove()
{
	skybox->remove();
	skydome->remove();
//	terrain->remove();
	lamp->remove();
	ninja->remove();
	dwarf->remove();
}

