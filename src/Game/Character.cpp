#include "../headers/Character.hpp"
#include <stdlib.h>

Character::Character(irr::IrrlichtDevice *_device, const tl::path &mesh_path, const tl::path &texture_path, tl::vector3df position)
{
	device = _device;
	smgr = device->getSceneManager();
	driver = device->getVideoDriver();

	irr::scene::IAnimatedMesh *mesh = smgr->getMesh(mesh_path);
	
	if(!mesh)
	{
		device->drop();
		exit(1);
	}
	node = smgr->addAnimatedMeshSceneNode(mesh, 0,/* IDFlag_IsPickable*/0);
       	if(node)
	{
		node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		node->setPosition(position);
	       	node->setMaterialTexture(0, driver->getTexture(texture_path));
	}
}


Character::Character(irr::IrrlichtDevice *_device, const tl::path &mesh_path, tl::vector3df position, tl::ITriangleSelector *selector)
{
	device = _device;
	smgr = device->getSceneManager();
	driver = device->getVideoDriver();

	node = smgr->addAnimatedMeshSceneNode(smgr->getMesh(mesh_path), 0, 1<<0 | 1<<1);
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
}

tl::AnimNode *Character::getAnimNode()
{
	return node;
}
