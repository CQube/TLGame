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

	//TODO add convect func for degre to rad
	float xf = playerPos.X - cos(direction * irr::core::PI / 180.0f) * 64.0f;
	float yf = playerPos.Y - sin(zdirection * irr::core::PI / 180.0f) * 64.0f;
	float zf = playerPos.Z + sin(direction * irr::core::PI / 180.0f) * 64.0f;
	
	camera->setPosition(irr::core::vector3df(xf, yf, zf));
	camera->setTarget(playerPos);
	focus_node->setRotation(irr::core::vector3df(0, direction, 0));
}
