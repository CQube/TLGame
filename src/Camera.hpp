#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <irrlicht/irrlicht.h>

class Camera
{
private:
	irr::IrrlichtDevice *device;
	irr::scene::IAnimatedMeshSceneNode *focus_node;
	float zdirection;
	float direction;
	irr::core::position2d<irr::f32> cursorPos;
	irr::scene::ICameraSceneNode *camera;
	irr::core::vector3df cameraPos;
	
public:
	Camera(irr::IrrlichtDevice *device);
	void setFocusMesh(irr::scene::IAnimatedMeshSceneNode *new_focus_node);
	void update();
};

#endif //CAMERA_HPP
