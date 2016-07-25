#include "MainFrame.h"

MainFrame::MainFrame(const wxString& title, std::shared_ptr<EntriesHandler> eh) : wxFrame(NULL, wxID_ANY, title) {
	_panel = new wxPanel(this, wxID_ANY);
	createButtons(eh);
}

void MainFrame::createButtons(std::shared_ptr<EntriesHandler> eh) {
	for (unsigned int i = 0; i < eh->getList().size(); i++) {
		std::unique_ptr<wxButton> button(new wxButton(_panel, wxID_ANY, eh->getList().at(i)->getName(), wxPoint(0 + eh->getList().at(i)->getTier()*80, 0 + i * 80)));
		button->Show(true);
		_buttons.push_back(std::move(button));

		//std::unique_ptr<Entry> ptr(new Entry(data.at(0)));
		//_list.push_back(std::move(ptr));
	}
}