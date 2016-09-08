#include "Camera.hpp"

Camera::Camera(irr::IrrlichtDevice *_device)
{
	device    = _device;
        camera    = device->getSceneManager()->getActiveCamera();
	cameraPos = camera->getAbsolutePosition();

	direction  = 0;
	zdirection = 0;
}

void Camera::setFocusMesh(irr::scene::IAnimatedMeshSceneNode *new_focus_node)
{
	focus_node = new_focus_node;
}

void Camera::update()
{
	cursorPos = device->getCursorControl()->getRelativePosition();

	float changeX = (cursorPos.X - 0.5f) * 256.0f;
	float changeY = (cursorPos.Y - 0.5f) * 256.0f;

	direction  += changeX;
	zdirection += changeY;
	if (zdirection < -90)
		zdirection = -90;
	else if (zdirection > 90)
		zdirection = 90;

	device->getCursorControl()->setPosition(0.5f, 0.5f);

	irr::core::vector3df playerPos = focus_node->getPosition();

	irr::core::vector3df newCameraPos;
        newCameraPos.X = playerPos.X - cos(degToRad(direction)) * 64.0f;
        newCameraPos.Y = playerPos.Y - sin(degToRad(zdirection)) * 64.0f;
        newCameraPos.Z = playerPos.Z + sin(degToRad(direction)) * 64.0f;
	
	camera->setPosition(newCameraPos);
	camera->setTarget(playerPos);
	focus_node->setRotation(irr::core::vector3df(0, direction, 0));
}

float Camera::degToRad(float degre)
{
	return degre * irr::core::PI / 180.0f;
}
