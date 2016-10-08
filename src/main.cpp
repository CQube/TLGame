// #include <irrlicht/irrlicht.h>
// #include <irrlicht/driverChoice.h>
// #include "EventReceiver.h"
// #include "Game/Camera.hpp"
// #include "Game/Character.hpp"
// #include "typedefs.hpp"
// #include "Game/Level.hpp"
// #include "Game/MainHero.hpp"
#include "Game/Game.hpp"

int main()
{	
	
	//if (device == 0)
	//	return 1;
	
	//video::IVideoDriver* driver = device->getVideoDriver();
	//scene::ISceneManager* smgr = device->getSceneManager();

	//Level *level = new Level(device);
	//level->loadLevel();
	
        //device->getCursorControl()->setVisible(false);
	
	//level->run();
	
	//device->drop();

	Game *game = new Game();
	game->loop();
	
	return 0;
}
