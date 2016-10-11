#include "InputReceiver.hpp"

InputReceiver::InputReceiver()
{
	for (u32 i = 0; i < KEY_KEY_CODES_COUNT; ++i)
		KeyIsDown[i] = false;
}

bool InputReceiver::OnEvent(const SEvent& event)
{
	if (event.EventType == irr::EET_KEY_INPUT_EVENT)
		KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
	
	return false;
}

bool InputReceiver::IsKeyDown(EKEY_CODE keyCode) const
{
	return KeyIsDown[keyCode];
}
