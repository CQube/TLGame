#ifndef LEVEL
#define LEVEL
#include <irrlicht/irrlicht.h>

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

public:
	Level(irr::IrrlichtDevice *_device);
	void addTerrainSceneNode();
	void addLightning();
	void addSkyBox();
	void addSkyDome();
	void loadLevel();
	irr::scene::ITriangleSelector *getTrSelector();
};

#endif //LEVEL
