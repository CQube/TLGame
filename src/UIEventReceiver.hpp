#ifndef GUIReceiver
#define GUIReceiver

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

void setSkinTransparency(s32 alpha, irr::gui::IGUISkin * skin)
{
    for (s32 i = 0; i < irr::gui::EGDC_COUNT; ++i)
    {
        video::SColor col = skin->getColor((EGUI_DEFAULT_COLOR)i);
        col.setAlpha(alpha);
        skin->setColor((EGUI_DEFAULT_COLOR)i, col);
    }
}

class UIEventReceiver : public IEventReceiver
{
private:
	SAppContext *Context;
	
public:
	UIEventReceiver(SAppContext * context)
		{
			Context = context;
		}

	
	virtual bool OnEvent(const SEvent& event)
		{
			if (event.EventType == EET_GUI_EVENT)
			{
				s32 id = event.GUIEvent.Caller->getID();
				IGUIEnvironment* env = Context->device->getGUIEnvironment();

				switch(event.GUIEvent.EventType)
				{
				case EGET_SCROLL_BAR_CHANGED:
					if (id == GUI_ID_TRANSPARENCY_SCROLL_BAR)
					{
						s32 pos = ((IGUIScrollBar*)event.GUIEvent.Caller)->getPos();
						setSkinTransparency(pos, env->getSkin());
					}
					break;
				case EGET_BUTTON_CLICKED:
					switch(id)
					{
					case GUI_ID_QUIT_BUTTON:
						Context->device->closeDevice();
						return true;

					case GUI_ID_NEW_WINDOW_BUTTON:
					{
						Context->listbox->addItem(L"Window created");
						Context->counter += 30;
						if (Context->counter > 200)
							Context->counter = 0;

						IGUIWindow* window = env->addWindow(
							rect<s32>(100 + Context->counter, 100 + Context->counter,
								  300 + Context->counter, 200 + Context->counter),
							false, // modal?
							L"Test window");

						env->addStaticText(L"Please close me",
								   rect<s32>(35,35,140,50),
								   true, // border?
								   false, // wordwrap?
								   window);
					}
					return true;

					case GUI_ID_FILE_OPEN_BUTTON:
						Context->listbox->addItem(L"File open");
						env->addFileOpenDialog(L"Please choose a file.", true, 0, -1, true);
						return true;

					default:
						return false;
					}
					break;

				case EGET_FILE_SELECTED:
				{
					// show the model filename, selected in the file dialog
					IGUIFileOpenDialog* dialog =
						(IGUIFileOpenDialog*)event.GUIEvent.Caller;
					Context->listbox->addItem(dialog->getFileName());
				}
				break;

				default:
					break;
				}
			}

			return false;
		}
};


#endif //GUIReceiver
