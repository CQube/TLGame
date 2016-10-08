#ifndef GAME
#define GAME
#include <irrlicht/irrlicht.h>
#include "../typedefs.hpp"
#include "../EventReceiver.h"
#include "Camera.hpp"
#include "Character.hpp"
#include "Level.hpp"
#include "MainHero.hpp"


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
	EventReceiver receiver;
	State state;

	void game();
	void menu();
	void cursorVisible(bool visible);
public:
	Game();
	void loop();
};
























#endif //GAME
