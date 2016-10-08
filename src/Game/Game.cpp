#include "Game.hpp"

Game::Game() : state(INGAME)
{
	device = createDevice(EDT_OPENGL, core::dimension2d<u32>(640, 480),
			      16, false, false, false, &receiver);
	if (device == 0)
		return;
	state = INGAME;
	driver = device->getVideoDriver();
	smgr = device->getSceneManager();	
	interface = new UserInterface(device);                     
	level = new Level(device);

}

void Game::showCursor(bool visible)
{
	device->getCursorControl()->setVisible(visible);
}
	
void Game::menu()
{
        showCursor(true);
       	interface->menu();                                                	
}

void Game::game()
{
        showCursor(false);
	level->run();
	if (receiver.IsKeyDown(KEY_ESCAPE))
	{
		state = MENU;
		showCursor(true);
	}

}

void Game::loop()
{
	level->loadLevel();
	interface->loadInterface();  
	
	while(device->run())
	{
		switch (state) {
		case MENU: {
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

	
