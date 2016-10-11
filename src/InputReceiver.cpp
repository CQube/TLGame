#include "InputReceiver.hpp"
#include "Camera.hpp"

InputReceiver::InputReceiver()
{
	for (u32 i = 0; i < KEY_KEY_CODES_COUNT; ++i)
		KeyIsDown[i] = false;
}

bool InputReceiver::OnEvent(const SEvent& event)
{
	// Remember whether each key is down or up
	if (event.EventType == irr::EET_KEY_INPUT_EVENT)
		KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
		
	return false;
}

bool InputReceiver::IsKeyDown(EKEY_CODE keyCode) const
{
	return KeyIsDown[keyCode];
}
	
void InputReceiver::ProcessInput(MainHero *mainHero)
{		
	if(IsKeyDown(irr::KEY_KEY_W)){
		mainHero->changeDirection(X);
		mainHero->changeSpeed(MOVEMENT_SPEED);
		mainHero->changeAnimationType(EMAT_RUN);
	}
	if(IsKeyDown(irr::KEY_KEY_S)){
		mainHero->changeDirection(X);
		mainHero->changeSpeed(-1 * MOVEMENT_SPEED);
		mainHero->changeAnimationType(EMAT_FALLBACK);
	}
        if(IsKeyDown(irr::KEY_KEY_D)){
		mainHero->changeDirection(Z);
		mainHero->changeSpeed(-1 * MOVEMENT_SPEED / 3 * 2);
		mainHero->changeAnimationType(EMAT_RUN);
	}
	if(IsKeyDown(irr::KEY_KEY_A)){
		mainHero->changeDirection(Z);
		mainHero->changeSpeed(MOVEMENT_SPEED / 3 * 2);
		mainHero->changeAnimationType(EMAT_RUN);
	}
	if(IsKeyDown(irr::KEY_KEY_V)){
		mainHero->changeDirection(Y);
		mainHero->changeSpeed(5);
		mainHero->changeAnimationType(EMAT_JUMP);
	}
}
