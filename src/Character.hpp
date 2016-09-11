#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <irrlicht/irrlicht.h>

class Character 
{
private:
	
	irr::IrrlichtDevice *device;
	scene::ISceneManager *smgr;
	video::IVideoDriver *driver;
	core::vector3df position;
	irr::scene::IAnimatedMeshSceneNode *node;
	const io::path & mesh_path;
	const io::path & texture_path;
	
public:
	Character(irr::IrrlichtDevice *_device);
//	irr::scene::IAnimatedMeshSceneNode *createCharacter(const io::path &mesh_path);

	irr::scene::IAnimatedMeshSceneNode *getNode();
	void createCharacter(const io::path &mesh_path, const io::path &texture_path, core::vector3df position);
	
};


#endif //CHARACTER_HPP
