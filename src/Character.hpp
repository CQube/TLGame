#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <irrlicht/irrlicht.h>

class Character 
{
private:
	
	irr::IrrlichtDevice *device;
	irr::scene::ISceneManager *smgr;
	irr::video::IVideoDriver *driver;
	irr::core::vector3df position;
	irr::scene::IAnimatedMeshSceneNode *node;
	
public:
	Character(irr::IrrlichtDevice *_device);
//to do-	irr::scene::IAnimatedMeshSceneNode *createCharacter(const io::path &mesh_path);

//to do-	irr::scene::IAnimatedMeshSceneNode *getNode();
	irr::scene::IAnimatedMeshSceneNode *createCharacter(const irr::io::path &mesh_path, const irr::io::path &texture_path, irr::core::vector3df position);
	
};


#endif //CHARACTER_HPP
