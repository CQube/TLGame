#ifndef MAIN_HERO_HPP
#define MAIN_HERO_HPP

#include <irrlicht/irrlicht.h>
#include "Character.hpp"
#include "../typedefs.hpp"
#include "../InputReceiver.hpp"

using namespace tl;

class MainHero: public Character
{
public:
	MainHero(irr::IrrlichtDevice *_device,
		 const tl::path &mesh_path,
		 const tl::path &texture_path,
		 tl::vector3df position) : Character(_device, mesh_path, texture_path, position){};

	MainHero(irr::IrrlichtDevice *_device,
		 const tl::path &mesh_path,
		 tl::vector3df position,
		 tl::ITriangleSelector *selector) : Character(_device, mesh_path, position, selector){};

	void addTrSelector(ITriangleSelector *_selector);
	void oMove (AnimNode *obj, f32 x, f32 y, f32 z);
	void Turn (AnimNode *obj, f32 x, f32 y, f32 z);
	void Move(InputReceiver *receiver);
	

};

#endif //MAIN_HERO_HPP
