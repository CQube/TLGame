#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <irrlicht/irrlicht.h>
#include "../typedefs.hpp"

using namespace tl;

class Camera
{
private:
	irr::IrrlichtDevice *device;
        AnimNode *focus_node;
	float zdirection;
	float direction;
	irr::core::position2d<irr::f32> cursorPos;
	irr::scene::ICameraSceneNode *camera;
	irr::core::vector3df cameraPos;

	float degToRad(float degre);
	
public:
	Camera(irr::IrrlichtDevice *device);
	void setFocusMesh(AnimNode *new_focus_node);
	void update();
};

#endif //CAMERA_HPP
