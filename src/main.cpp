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
	
        device->getCursorControl()->setVisible(false);
	
	level->run();
	
	device->drop();
	
	return 0;
}
