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

irr::scene::ITriangleSelector *Level::loadLevel()
{
	SCamera = smgr->addCameraSceneNode(0, irr::core::vector3df(-50.0f,50.0f,0.0f) ,
					   irr::core::vector3df(0.0f,0.0f,0.0f), -1);
	addTerrainSceneNode();
	addLightning();
	addSkyBox();
	addSkyDome();
	driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, true);
	return selector;
}
