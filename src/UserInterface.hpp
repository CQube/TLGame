#ifndef USER_INTERFACE_HPP
#define USER_INTERFACE_HPP

#include <irrlicht/irrlicht.h>
#include "typedefs.hpp"
#include "UIEventReceiver.hpp"

using namespace tl;


class UserInterface
{
private:
	IrrlichtDevice        *device;
	IVideoDriver          *driver;
	IGUIEnvironment       *env;
	IGUISkin              *skin;
	IGUIFont              *font;
	SAppContext           *context;
	IGUIScrollBar         *scrollbar;
	IGUIListBox           *listbox; 
	UIEventReceiver       *receiver;
public:
	UserInterface(IrrlichtDevice * _device);
	void addScrollbar();
	void addButtons();
	void setFont();
	void menu();
	void loadInterface();
};



#endif //USERINTERFACE_HPP
