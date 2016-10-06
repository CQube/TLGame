#ifndef LEVEL
#define LEVEL
#include <irrlicht/irrlicht.h>
#include "../typedefs.hpp"
#include "MainHero.hpp"
#include "../EventReceiver.h"
//#include "../UserInterface.hpp"        //раскомментить

class Level
{
private:
	irr::IrrlichtDevice                   *device;
	irr::video::IVideoDriver              *driver;
	irr::scene::ICameraSceneNode          *SCamera;
	irr::scene::ISceneManager             *smgr;
	irr::scene::ISceneNode                *skydome;
	irr::scene::ISceneNode                *skybox;
	irr::scene::ILightSceneNode           *lamp;
	irr::scene::ITriangleSelector         *selector;
	irr::scene::IMetaTriangleSelector     *meta;
	irr::scene::ISceneNodeAnimator        *anim;
	irr::scene::ITerrainSceneNode         *terrain;
	MainHero                              *sydney;
	MyEventReceiver                       *receiver;
	
public:
	Level(irr::IrrlichtDevice *_device);
	void addTerrainSceneNode();
	void addLightning();
	void addSkyBox();
	void addSkyDome();
	void addMainHero();
	void addCharacters();
	void loadLevel();
	irr::scene::ITriangleSelector *getTrSelector();

	void run();
};

#endif //LEVEL
