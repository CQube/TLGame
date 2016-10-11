#ifndef INPUTRECEIVER_HPP
#define INPUTRECEIVER_HPP

#include <irrlicht/irrlicht.h>
#include "Game/MainHero.hpp"
using namespace irr;

class MainHero;

class InputReceiver : public IEventReceiver
{
	
private:
	bool KeyIsDown[KEY_KEY_CODES_COUNT];
	MainHero *syd;
public:
	InputReceiver();
	virtual bool OnEvent(const SEvent& event);
	virtual bool IsKeyDown(EKEY_CODE keyCode) const;
	void smt();

};

#endif //INPUTRECEIVER_HPP
