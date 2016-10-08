#ifndef GAME
#define GAME
#include <irrlicht/irrlicht.h>
#include "../typedefs.hpp"
#include "../EventReceiver.h"
#include "Camera.hpp"
#include "Character.hpp"
#include "Level.hpp"
#include "MainHero.hpp"
#include "../GUI/UserInterface.hpp"

enum State{
	MENU = 0,
	INGAME
};


class Game
{
private:

	IrrlichtDevice* device;
	IVideoDriver* driver;
	ISceneManager* smgr;
	Level *level;
	UserInterface *interface;
	EventReceiver receiver;
	State state;

	void game();
	void menu();
	void showCursor(bool visible);
public:
	Game();
	void loop();
};
























#endif //GAME
