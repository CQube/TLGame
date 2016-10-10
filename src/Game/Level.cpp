#include "../headers/Level.hpp"
#include "../headers/Camera.hpp"

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
	receiver = (MyEventReceiver *)device->getEventReceiver();
}

void Level::addTerrainSceneNode()
{
	terrain = smgr->addTerrainSceneNode(
		"../media/terrain-heightmap.bmp",
		0,                    //родитель
		-1,                   //ID
		irr::core::vector3df(0, 0, 0),   //позиция
		irr::core::vector3df(0, 0, 0),   //поворот
		irr::core::vector3df(40, 2, 40), //масштаб
		irr::video::SColor(255, 255, 255, 255),//цвета вершин
		5,                    //максимум LOD
		irr::scene::ETPS_17,              //размер патча
		4);                   //коэфф. размытия
	terrain->setMaterialTexture(0 , driver->getTexture("../media/terrain-texture.jpg"));
	terrain->setMaterialTexture(1 , driver->getTexture("../media/detailmap3.jpg"));
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
	skybox = smgr->addSkyBoxSceneNode(
		driver->getTexture("../media/irrlicht2_up.jpg"),
		driver->getTexture("../media/irrlicht2_dn.jpg"),
		driver->getTexture("../media/irrlicht2_lf.jpg"),
		driver->getTexture("../media/irrlicht2_rt.jpg"),
		driver->getTexture("../media/irrlicht2_ft.jpg"),
		driver->getTexture("../media/irrlicht2_bk.jpg"));
}

void Level::addSkyDome()
{
	skydome = smgr->addSkyDomeSceneNode(driver -> getTexture("../media/skydome.jpg"), 16, 8, 0.95f, 2.0f);
}

void Level::addMainHero()
{
	sydney = new MainHero(device, "../media/sydney.md2", "../media/sydney.bmp", vector3df(180, 200, 0));
	AnimNode *node_sydney = sydney->getAnimNode();
	node_sydney->setScale(core::vector3df(1.5f));
	node_sydney->setMD2Animation(scene::EMAT_STAND);

	sydney->addTrSelector(selector);

}

void Level::addCharacters()
{
        Character *ninja = new Character(device, "../media/ninja.b3d", vector3df(3071, 400, 1970), selector);
        AnimNode *node_ninja = ninja->getAnimNode();
	
	Character *dwarf = new Character(device, "../media/dwarf.x", vector3df(2760, 480, 3705), selector);
        AnimNode *node_dwarf = dwarf->getAnimNode();
	node_dwarf->setRotation(vector3df(0, 20, 0));
}

void Level::loadLevel()
{
	SCamera = smgr->addCameraSceneNode(0, irr::core::vector3df(-50.0f,50.0f,0.0f) ,
					   irr::core::vector3df(0.0f,0.0f,0.0f), -1);
	addTerrainSceneNode();
	addLightning();
	addSkyBox();
	addSkyDome();
	driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, true);
	addMainHero();
	addCharacters();
}

irr::scene::ITriangleSelector *Level::getTrSelector()
{
	return selector;
}

void Level::run()
{
	Camera* camera = new Camera(device);
	camera->setFocusMesh(sydney->getAnimNode());
	
	while(device->run())
	{
		sydney->Move(receiver);
		if(receiver->IsKeyDown(irr::KEY_KEY_Q)){
			vector3df pos_node = sydney->getAnimNode()->getPosition();
			//std::cout << pos_node.X<<" " << pos_node.Y<<" " << pos_node.Z << std::endl;
		}
		
		camera->update();
		
		driver->beginScene(true, true, video::SColor(255,113,113,133));
		smgr->drawAll();
	       	device->getGUIEnvironment()->drawAll();

		driver->endScene();
	}
}
