#include "MainHero.hpp"

void MainHero::oMove (AnimNode *obj, f32 x, f32 y, f32 z)
{
	vector3df move;
	matrix4 matrix;

	move = vector3df(x, y, z);

	matrix.setRotationDegrees(obj->getRotation());
	matrix.transformVect(move);

	obj->setPosition(obj->getPosition() + move);
}

void MainHero::Turn (AnimNode *obj, f32 x, f32 y, f32 z)
{
	obj->setRotation(obj->getRotation() + vector3df(x, y, z));
}

void MainHero::Move(EventReceiver *receiver)
{
	core::vector3df nodePosition_sydney = node->getPosition();

	if(receiver->IsKeyDown(irr::KEY_KEY_W)){
		oMove(node, MOVEMENT_SPEED, 0, 0);
	}
	if(receiver->IsKeyDown(irr::KEY_KEY_S)){
		oMove(node, -1 * MOVEMENT_SPEED, 0, 0);
	}
        if(receiver->IsKeyDown(irr::KEY_KEY_D)){
		//Turn(node_sydney, 0, 5, 0);
		oMove(node, 0, 0, -1 * MOVEMENT_SPEED / 3 * 2);
	}
	if(receiver->IsKeyDown(irr::KEY_KEY_A)){
		//Turn(node_sydney, 0, 0, 0);
		oMove(node, 0, 0, MOVEMENT_SPEED / 3 * 2);
	}
	if(receiver->IsKeyDown(irr::KEY_KEY_V)){
		//Turn(node_sydney, 0, 5, 0);
		oMove(node, 0, 10, 0);
	}
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
