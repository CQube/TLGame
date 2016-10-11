#include "MainHero.hpp"

void MainHero::oMove ()
{
	matrix4 matrix;

	move = vector3df(x, y, z);

	matrix.setRotationDegrees(node->getRotation());
	matrix.transformVect(Speed);

	node->setPosition(node->getPosition() + Speed);
}

void MainHero::Turn (AnimNode *obj, f32 x, f32 y, f32 z)
{
	obj->setRotation(obj->getRotation() + vector3df(x, y, z));
}

void MainHero::Move(InputReceiver *receiver)
{		
	core::vector3df nodePosition_sydney = node->getPosition();

	receiver->ProcessInput(this);

}

void MainHero::addTrSelector(tl::ITriangleSelector* selector)
{
	if (!selector)
		exit(1);
	
	scene::ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(
		selector, node, core::vector3df(30,50,30),
		core::vector3df(0,-10,0), core::vector3df(0,0,0));
	selector->drop();
	node->addAnimator(anim);
	anim->drop(); 
}

void MainHero::changeDirection(Direction _direction)
{
	direction = _direction;
}

void MainHero::changeSpeed(f32 _speed)
{
	switch(direction){
	case 1:
		Speed = (_speed, 0, 0)
			break;
	case 2:
		
		Speed = (0, _speed, 0)
			break;
	case 3:
		
		Speed = (0, 0, _speed)
	}
}

void MainHero::cahngeAnimationFlag(EMD2_ANIMATION_TYPE anim_type)
{
	node_sydney->setMD2Animation(anim_type);
}
