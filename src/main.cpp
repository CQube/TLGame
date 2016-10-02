#include <irrlicht/irrlicht.h>
#include <irrlicht/driverChoice.h>
#include "MyEventReceiver.h"
#include "Game/Camera.hpp"
#include "Game/Character.hpp"
#include "typedefs.hpp"
#include "Game/Level.hpp"
#include "Game/MainHero.hpp"

using namespace tl;

//TODO mv to new file
void oMove (AnimNode *obj, f32 x, f32 y, f32 z);
void Turn (AnimNode *obj, f32 x, f32 y, f32 z);
void SidneyMove(AnimNode *node_sydney, MyEventReceiver *receiver);

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

	Level *level = new Level(device);
	level->loadLevel();
	ITriangleSelector *selector = level->getTrSelector();
 	
	MainHero *sydney = new MainHero(device, "../media/sydney.md2", "../media/sydney.bmp", vector3df(180, 200, 0));
	AnimNode *node_sydney = sydney->getAnimNode();
	node_sydney->setScale(core::vector3df(1.5f));
	node_sydney->setMD2Animation(scene::EMAT_STAND);

	sydney->addTrSelector(selector);
	
        Character *ninja = new Character(device, "../media/ninja.b3d", vector3df(3071, 400, 1970), selector);
        AnimNode *node_ninja = ninja->getAnimNode();
	
	Character *dwarf = new Character(device, "../media/dwarf.x", vector3df(2760, 480, 3705), selector);
        AnimNode *node_dwarf = dwarf->getAnimNode();
	node_dwarf->setRotation(vector3df(0, 20, 0));
	 
	device->getCursorControl()->setVisible(false);
	
	Camera* camera = new Camera(device);
	camera->setFocusMesh(node_sydney);

	//TODO mv to Level
	while(device->run())
	if (device->isWindowActive())
	{
		sydney->Move(&receiver);
		if(receiver.IsKeyDown(irr::KEY_KEY_Q)){
			vector3df pos_node = node_sydney->getPosition();
			std::cout << pos_node.X<<" " << pos_node.Y<<" " << pos_node.Z << std::endl;
		}
		
		camera->update();
		
		driver->beginScene(true, true, video::SColor(255,113,113,133));
		smgr->drawAll();
	       	device->getGUIEnvironment()->drawAll();

		driver->endScene();
	        
	}
	
	
	device->drop();
	
	return 0;
}
