#ifndef MAINHERO_HPP
#define MAINHERO_HPP

#include <irrlicht/irrlicht.h>
#include "../typedefs.hpp"
#include "Character.hpp"
#include "../InputReceiver.hpp"

using namespace tl;

class MainHero: public Character
{
private:
	Direction direction;
	vector3df Speed;
	EMD2_ANIMATION_TYPE animationType;
	
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
	void oMove (f32 x, f32 y, f32 z);
	void Turn (AnimNode *obj, f32 x, f32 y, f32 z);
	void Move(InputReceiver *receiver);
	void changeDirection(Direction direction);
	void changeSpeed(f32 speed);
	void changeAnimationType(EMD2_ANIMATION_TYPE anim_type);
};

#endif //MAINHERO_HPP
