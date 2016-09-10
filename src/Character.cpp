#include "Character.hpp"

Character::Character(irr::IrrlichtDevice *_device)
{
	device = _device;
	smgr = device->getSceneManager();
	driver = device->getVideoDriver();
}

irr::scene::IAnimatedMeshSceneNode *Character::createCharacter(const io::path &mesh_path, const io::path &texture_path, core::vector3df position)
{
	irr::scene::IAnimatedMesh *mesh = smgr->getMesh(mesh_path);
	
	if(!mesh)
	{
		device->drop();
		return 0;
	}
	irr::scene::IAnimatedMeshSceneNode *node = smgr->addAnimatedMeshSceneNode(mesh, 0, IDFlag_IsPickable);
       	if(node)
	{
		node->setMaterialFlag(video::EMF_LIGHTING, false);
		node->setPosition(position);
	       	node->setMaterialTexture(0, driver->getTexture(texture_path));
	}
	return node;
}

