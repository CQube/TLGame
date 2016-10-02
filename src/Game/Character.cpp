#include "Character.hpp"

Character::Character(irr::IrrlichtDevice *_device)
{
	device = _device;
	smgr = device->getSceneManager();
	driver = device->getVideoDriver();
}

tl::AnimNode *Character::createCharacter(const irr::io::path &mesh_path, const irr::io::path &texture_path, irr::core::vector3df position)
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

tl::AnimNode *Character::createCharacter(const irr::io::path &mesh_path, irr::core::vector3df position, irr::scene::ITriangleSelector *selector)
{
	tl::AnimNode *node = smgr->addAnimatedMeshSceneNode(smgr->getMesh(mesh_path), 0, 1<<0 | 1<<1);
	node->setScale(irr::core::vector3df(10));
	node->setPosition(position);
        node->setRotation(irr::core::vector3df(0,-160,0));
	node->setAnimationSpeed(8.f);
	node->getMaterial(0).NormalizeNormals = true;
	node->getMaterial(0).Lighting = true;
	// Just do the same as we did above.
	selector = smgr->createTriangleSelector(node);
	node->setTriangleSelector(selector);
	selector->drop();
	return node;
}
