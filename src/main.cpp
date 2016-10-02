#include <irrlicht/irrlicht.h>
#include <irrlicht/driverChoice.h>
#include "MyEventReceiver.h"
#include "Game/Camera.hpp"
#include "Game/Character.hpp"
#include "typedefs.hpp"
#include "Game/Level.hpp"

using namespace tl;

void oMove (AnimNode *obj, f32 x, f32 y, f32 z);
void Turn (AnimNode *obj, f32 x, f32 y, f32 z);
void SidneyMove(AnimNode *node_sydney, MyEventReceiver *receiver);

int main()
{	
	MyEventReceiver receiver;
	
	IrrlichtDevice* device =
		createDevice(EDT_OPENGL, core::dimension2d<u32>(640, 480),
			     16, false, false, false, &receiver);
	
	if (device == 0)
		return 1;
	
	video::IVideoDriver* driver = device->getVideoDriver();
	scene::ISceneManager* smgr = device->getSceneManager();

	Level *level = new Level(device);
	level->loadLevel();
	ITriangleSelector *selector = level->getTrSelector();
 	
	Character *Sydney = new Character(device);
	AnimNode *node_sydney = Sydney->createCharacter("../media/sydney.md2", "../media/sydney.bmp", vector3df(180, 200, 0) );
	node_sydney->setScale(core::vector3df(1.5f));
	node_sydney->setMD2Animation(scene::EMAT_STAND);

	//Collisions
	if (selector)
	{
		scene::ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(
			selector, node_sydney, core::vector3df(30,50,30),
			core::vector3df(0,-10,0), core::vector3df(0,0,0));
		selector->drop();
		node_sydney->addAnimator(anim);
		anim->drop(); 
	}

	Character *Ninja = new Character(device);
       	AnimNode *node_ninja = Ninja->createCharacter("../media/ninja.b3d", vector3df(3071, 400, 1970), selector);

	Character *Dwarf = new Character(device);
        AnimNode *node_dwarf = Dwarf->createCharacter("../media/dwarf.x", vector3df(2760, 480, 3705), selector);
	node_dwarf->setRotation(vector3df(0, 20, 0));
	 
	device->getCursorControl()->setVisible(false);
	
	Camera* camera = new Camera(device);
	camera->setFocusMesh(node_sydney);
	
	while(device->run())
	if (device->isWindowActive())
	{
		SidneyMove(node_sydney, &receiver);
		if(receiver.IsKeyDown(irr::KEY_KEY_Q)){
			vector3df pos_node = node_sydney->getPosition();
			std::cout << pos_node.X<<" " << pos_node.Y<<" " << pos_node.Z << std::endl;
		}
		
		camera->update();
		
		driver->beginScene(true, true, video::SColor(255,113,113,133));
		smgr->drawAll();
	       	device->getGUIEnvironment()->drawAll();

		driver->endScene();
	        
	}
	
	
	device->drop();
	
	return 0;
}

void oMove (AnimNode *obj, f32 x, f32 y, f32 z)
{
	vector3df move;
	matrix4 matrix;

	move = vector3df(x, y, z);

	matrix.setRotationDegrees(obj -> getRotation());
	matrix.transformVect(move);

	obj -> setPosition(obj -> getPosition() + move);
}

void Turn (AnimNode *obj, f32 x, f32 y, f32 z)
{
	obj -> setRotation(obj -> getRotation() + vector3df(x, y, z));
}

void SidneyMove(AnimNode *node_sydney, MyEventReceiver *receiver)
{
	core::vector3df nodePosition_sydney = node_sydney->getPosition();

	if(receiver->IsKeyDown(irr::KEY_KEY_W)){
		oMove(node_sydney, MOVEMENT_SPEED, 0, 0);
	}
	if(receiver->IsKeyDown(irr::KEY_KEY_S)){
		oMove(node_sydney, -1 * MOVEMENT_SPEED, 0, 0);
	}
        if(receiver->IsKeyDown(irr::KEY_KEY_D)){
		//Turn(node_sydney, 0, 5, 0);
		oMove(node_sydney, 0, 0, -1 * MOVEMENT_SPEED / 3 * 2);
	}
	if(receiver->IsKeyDown(irr::KEY_KEY_A)){
		//Turn(node_sydney, 0, 0, 0);
		oMove(node_sydney, 0, 0, MOVEMENT_SPEED / 3 * 2);
	}
	if(receiver->IsKeyDown(irr::KEY_KEY_V)){
		//Turn(node_sydney, 0, 5, 0);
		oMove(node_sydney, 0, 10, 0);
	}
}
