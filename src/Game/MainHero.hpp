#ifndef MAIN_HERO_HPP
#define MAIN_HERO_HPP

#include <irrlicht/irrlicht.h>
#include "../typedefs.hpp"
#include "Character.hpp"
#include "../EventReceiver.h"

using namespace tl;

class MainHero: public Character
{
public:
	MainHero(irr::IrrlichtDevice *_device, IAnimatedMesh *_mesh, ITexture *_texture, tl::vector3df position):Character(_device, _mesh, _texture, position){};
	MainHero(irr::IrrlichtDevice *_device,  IAnimatedMesh *_mesh, tl::vector3df position, tl::ITriangleSelector *selector):Character(_device, _mesh, position, selector){};
	void addTrSelector(ITriangleSelector *_selector);
	void oMove (AnimNode *obj, f32 x, f32 y, f32 z);
	void Turn (AnimNode *obj, f32 x, f32 y, f32 z);
	void Move(EventReceiver *receiver);
};

#endif //MAIN_HERO_HPP
