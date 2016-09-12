#include "Character.hpp"

Character::Character(irr::IrrlichtDevice *_device)
{
	device = _device;
	smgr = device->getSceneManager();
	driver = device->getVideoDriver();
}

/*irr::scene::IAnimatedMeshSceneNode *getNode()
{
	return node;
}
*/
irr::scene::IAnimatedMeshSceneNode *Character::createCharacter(const irr::io::path &mesh_path, const irr::io::path &texture_path, irr::core::vector3df position)
{
	irr::scene::IAnimatedMesh *mesh = smgr->getMesh(mesh_path);
	
	if(!mesh)
	{
		device->drop();
	       	return 0;
	}
	node = smgr->addAnimatedMeshSceneNode(mesh, 0,/* IDFlag_IsPickable*/0);
       	if(node)
	{
		node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		node->setPosition(position);
	       	node->setMaterialTexture(0, driver->getTexture(texture_path));
	}
	return node;
}
