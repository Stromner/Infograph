#include "MainFrame.h"

MainFrame::MainFrame(const wxString& title, std::shared_ptr<EntriesHandler> eh) : wxFrame(NULL, wxID_ANY, title) {
	_panel = new wxPanel(this, wxID_ANY);
	createButtons(eh);
}

void MainFrame::createButtons(std::shared_ptr<EntriesHandler> eh) {
	int x_pos = 0;
	int tier = 0;
	for (unsigned int i = 0; i < eh->getList().size(); i++) {
		if (tier < eh->getList().at(i)->getTier()) {
			tier++;
			x_pos = 0;
		}
		std::unique_ptr<EntryButton> button(new EntryButton(_panel, eh->getList().at(i), x_pos));
		button->Show(true);
		_buttons.push_back(std::move(button));
		x_pos += 100;
	}
}