#ifndef INPUTRECEIVER_HPP
#define INPUTRECEIVER_HPP

#include <irrlicht/irrlicht.h>

using namespace irr;

class InputReceiver : public IEventReceiver
{
	
private:
	bool KeyIsDown[KEY_KEY_CODES_COUNT];

public:
	InputReceiver();
	virtual bool OnEvent(const SEvent& event);
	virtual bool IsKeyDown(EKEY_CODE keyCode) const;
};

#endif //INPUTRECEIVER_HPP
