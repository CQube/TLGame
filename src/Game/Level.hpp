#ifndef LEVEL
#define LEVEL
#include <irrlicht/irrlicht.h>
#include "../typedefs.hpp"
#include "MainHero.hpp"
#include "../EventReceiver.h"
#include "../GUI/UserInterface.hpp"        //раскомментить
#include "Camera.hpp"

const path media_folder =                 "../media/";
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
	EventReceiver                         *receiver;
	Camera                                *camera;

	ITexture                              *Up;
	ITexture                              *Down;
	ITexture                              *Left;
	ITexture                              *Right;
	ITexture                              *Forward;
	ITexture                              *Back;
	ITexture                              *skydome_texture;
	ITexture                              *terrain_texture1;
	ITexture                              *terrain_texture2;
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

//loads
	void loadSkyBoxTextures();
	void loadSkyDomeTextures();
//	void loadTerrainTextures();
//	void loadMainHeroTextures();

	void run();
	void remove();
};

#endif //LEVEL
