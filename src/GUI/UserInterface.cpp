#include "UserInterface.hpp"

UserInterface::UserInterface(IrrlichtDevice * _device)
{
	device = _device;
	driver = device->getVideoDriver();
	env = device->getGUIEnvironment();
}


void UserInterface::setFont()
{
	skin = env->getSkin();
	font = env->getFont("../media/fonthaettenschweiler.bmp"); //TODO change path to define
	if (font)
		skin->setFont(font);

	skin->setFont(env->getBuiltInFont(), EGDF_TOOLTIP);	
}

void UserInterface::addButtons()
{
	env->addButton(rect<s32>(10,240,110,240 + 32), 0, GUI_ID_QUIT_BUTTON,
		       L"Quit", L"Exits Program");
	env->addButton(rect<s32>(10,280,110,280 + 32), 0, GUI_ID_NEW_WINDOW_BUTTON,
		       L"New Window", L"Launches a new Window");
	env->addButton(rect<s32>(10,320,110,320 + 32), 0, GUI_ID_FILE_OPEN_BUTTON,
		       L"File Open", L"Opens a file");
}

void UserInterface::addScrollbar()
{
	env->addStaticText(L"Transparent Control:", rect<s32>(150,20,350,40), true);
	scrollbar = env->addScrollBar(true, rect<s32>(150, 45, 350, 60), 0, GUI_ID_TRANSPARENCY_SCROLL_BAR);
	scrollbar->setMax(255);
	scrollbar->setPos(255);
	setSkinTransparency( scrollbar->getPos(), env->getSkin());

	// set scrollbar position to alpha value of an arbitrary element
	scrollbar->setPos(env->getSkin()->getColor(EGDC_WINDOW).getAlpha());

	env->addStaticText(L"Logging ListBox:", rect<s32>(50,110,250,130), true);
	listbox = env->addListBox(rect<s32>(50, 140, 250, 210));
	env->addEditBox(L"Editable Text", rect<s32>(350, 80, 550, 100));

	// Store the appropriate data in a context structure.
	context = new SAppContext;
	context->device = device;
	context->counter = 0;
	context->listbox = listbox;
	
	// Store the appropriate data in a context structure.
	// Then create the event receiver, giving it that context structure.
	receiver = new UIEventReceiver(context);

	// And tell the device to use our custom event receiver.
	device->setEventReceiver(receiver);	
}


void UserInterface::menu() //in loop
{
	driver->beginScene(true, true, SColor(0,200,200,200));
	env->drawAll();
        driver->endScene();
}

void UserInterface::loadInterface()
{
        setFont();
        addButtons();
        addScrollbar();
}
