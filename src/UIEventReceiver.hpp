#ifndef UIEVENT_RECEIVER_HPP
#define UIEVENT_RECEIVER_HPP

#include <irrlicht/irrlicht.h>
#include "typedefs.hpp"

using namespace tl;

struct SAppContext
{
    IrrlichtDevice  *device;
    s32             counter;
    IGUIListBox    *listbox;
};


// Define some values that we'll use to identify individual GUI controls.
enum
{
    GUI_ID_QUIT_BUTTON = 101,
    GUI_ID_NEW_WINDOW_BUTTON,
    GUI_ID_FILE_OPEN_BUTTON,
    GUI_ID_TRANSPARENCY_SCROLL_BAR
};

class UIEventReceiver : public IEventReceiver
{	
private:
	SAppContext *Context;
	
public:
	void setSkinTransparency(s32 alpha, irr::gui::IGUISkin * skin);
	UIEventReceiver(SAppContext * context);
	bool OnEvent(const SEvent& event);
};


#endif //UIEVENT_RECEIVER_HPP
