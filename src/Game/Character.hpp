#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <irrlicht/irrlicht.h>
#include "../typedefs.hpp"
using namespace tl;
class Character 
{
protected:
	irr::IrrlichtDevice *device;
	irr::scene::ISceneManager *smgr;
	irr::video::IVideoDriver *driver;
	irr::core::vector3df position;
	tl::AnimNode *node;
	
public:
	Character(irr::IrrlichtDevice *_device, IAnimatedMesh *_mesh, ITexture *_texture, tl::vector3df position);
	Character(irr::IrrlichtDevice *_device, IAnimatedMesh *_mesh, tl::vector3df position, tl::ITriangleSelector *selector);
	tl::AnimNode *getAnimNode();
};


#endif //CHARACTER_HPP
