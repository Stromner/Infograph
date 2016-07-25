#include "MainFrame.h"

MainFrame::MainFrame(const wxString& title, std::shared_ptr<EntriesHandler> eh) : wxFrame(NULL, wxID_ANY, title) {
	_panel = new wxPanel(this, wxID_ANY);
	createButtons(eh);
}

void MainFrame::createButtons(std::shared_ptr<EntriesHandler> eh) {
	int xpos = 0;
	int tier = 0;
	for (unsigned int i = 0; i < eh->getList().size(); i++) {
		if (tier < eh->getList().at(i)->getTier()) {
			tier++;
			xpos = 0;
		}
		std::unique_ptr<wxButton> button(new 
			wxButton(_panel, wxID_ANY, eh->getList().at(i)->getName(), wxPoint(tier*150, xpos)));
		button->Show(true);
		_buttons.push_back(std::move(button));
		xpos += 100;
	}
}