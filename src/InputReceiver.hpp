#ifndef INPUTRECEIVER_HPP
#define INPUTRECEIVER_HPP

#include <irrlicht/irrlicht.h>
#include "typedefs.hpp"
#include "./Game/MainHero.hpp"

class InputReceiver : public IEvenrReceiver
{
private:
	bool KeyIsDown[KEY_KEY_CODES_COUNT];
	
public:
	InputReceiver();

	virtual bool OnEvent(const SEvent& event);
	virtual bool IsKeyDown(EKEY_CODE keyCode) const;
	void ProcessInput(MainHero *mainHero);
};

#endif //INPUTRECEIVER_HPP
