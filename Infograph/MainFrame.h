#include <wx\frame.h>
#include <wx\panel.h>
#include <iostream>
#include <wx\button.h>
#include "EntriesHandler.h"

#ifndef MAINFRAME_H
#define MAINFRAME_H

class MainFrame:public wxFrame{
public:
	MainFrame(const wxString& title, std::shared_ptr<EntriesHandler>);
private:
	void createButtons(std::shared_ptr<EntriesHandler>);
	std::vector<std::shared_ptr<wxButton>> _buttons;
	wxPanel *_panel;
};

#endif