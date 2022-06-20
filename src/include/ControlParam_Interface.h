#ifndef __ControlParam_Interface__
#define __ControlParam_Interface__

/**
@file
Subclass of ControlParam, which is generated by wxFormBuilder.
*/

#include "Layout.h"

//// end generated include

class MainFrame_Interface;
class Function;

/** Implementing ControlParam */
class ControlParam_Interface : public ControlParam
{
	protected:
		// Handlers for ControlParam events.
		void OnExit( wxCloseEvent& event );
		void Param1CtrlOnSpinCtrlDouble( wxSpinDoubleEvent& event );
		void Param2CtrlOnSpinCtrlDouble( wxSpinDoubleEvent& event );
		void Param3CtrlOnSpinCtrlDouble( wxSpinDoubleEvent& event );
	public:
		/** Constructor */
		ControlParam_Interface( wxWindow* parent );
	//// end generated class members
		ControlParam_Interface(wxWindow* parent, Function* fun);

		MainFrame_Interface* parent;
		Function* function;

};

#endif // __ControlParam_Interface__