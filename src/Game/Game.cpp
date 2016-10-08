#include "Game.hpp"

Game::Game() : state(MENU)
{
	device = createDevice(EDT_OPENGL, core::dimension2d<u32>(640, 480),
			      16, false, false, false, &receiver);
	if (device == 0)
		return;
	state = INGAME;
	driver = device->getVideoDriver();
	smgr = device->getSceneManager();	
}

void Game::cursorVisible(bool visible)
{
	device->getCursorControl()->setVisible(visible);
}
	
void Game::menu()
{

	
}

void Game::game()
{
	cursorVisible(false);
	level->run();
}

void Game::loop()
{
        
	
	level = new Level(device);
	level->loadLevel();
	while(device->run())
	{
		switch (state) {
		case MENU: {
			cursorVisible(true);
			menu();
			break;
		}
		case INGAME: {
			game();
			break;
		}
		}
	}
	device->drop();
}

	
