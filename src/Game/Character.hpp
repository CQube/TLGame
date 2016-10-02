#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <irrlicht/irrlicht.h>
#include "../typedefs.hpp"

class Character 
{
private:
	
	irr::IrrlichtDevice *device;
	irr::scene::ISceneManager *smgr;
	irr::video::IVideoDriver *driver;
	irr::core::vector3df position;
	tl::AnimNode *node;
	
public:
	Character(irr::IrrlichtDevice *_device);

	//TODO  
        //tl::AnimNode *getNode();
	
	tl::AnimNode *createCharacter(const irr::io::path &mesh_path, const irr::io::path &texture_path, irr::core::vector3df position);
	tl::AnimNode *createCharacter(const irr::io::path &mesh_path, irr::core::vector3df position, irr::scene::ITriangleSelector *selector);
};


#endif //CHARACTER_HPP
