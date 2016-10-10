#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <irrlicht/irrlicht.h>
#include "typedefs.hpp"

class Character 
{
protected:
	irr::IrrlichtDevice *device;
	irr::scene::ISceneManager *smgr;
	irr::video::IVideoDriver *driver;
	irr::core::vector3df position;
	tl::AnimNode *node;
	
public:
	Character(irr::IrrlichtDevice *_device, const tl::path &mesh_path, const tl::path &texture_path, tl::vector3df position);
	Character(irr::IrrlichtDevice *_device, const tl::path &mesh_path, tl::vector3df position, tl::ITriangleSelector *selector);

	tl::AnimNode *getAnimNode();
};


#endif //CHARACTER_HPP
