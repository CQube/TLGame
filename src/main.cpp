#include <irrlicht/irrlicht.h>
#include <irrlicht/driverChoice.h>
#include "../InputReceiver.hpp"
#include "Game/Camera.hpp"
#include "Game/Character.hpp"
#include "Game/Level.hpp"
#include "Game/MainHero.hpp"
#include "typedefs.hpp"

using namespace tl;

int main()
{	
	InputReceiver receiver;
	
	IrrlichtDevice* device =
		createDevice(EDT_OPENGL, core::dimension2d<u32>(640, 480),
			     16, false, false, false, &receiver);
	
	if (device == 0)
		return 1;
	
	video::IVideoDriver* driver = device->getVideoDriver();
	scene::ISceneManager* smgr = device->getSceneManager();

	Level *level = new Level(device);
	level->loadLevel();
	
	level->run();
	
	device->drop();
	
	return 0;
}
