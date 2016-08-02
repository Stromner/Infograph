#include "Main.h"

wxIMPLEMENT_APP(Main);

bool Main::OnInit() {
	_eh.reset(new EntriesHandler());
	_eh->calculateTier();
	
	wxFrame * _frame = new wxFrame(NULL, wxID_ANY, "Infograph");
	_panel = new wxPanel(_frame, wxID_ANY);

	createButtons();
	drawLines();

	_frame ->Show(true);
	return true;
}

void Main::createButtons() {
	int x_pos = 0;
	int tier = 0;
	for (unsigned int i = 0; i < _eh->getList().size(); i++) {
		if (tier < _eh->getList().at(i)->getTier()) {
			tier++;
			x_pos = 0;
		}
		EntryButton *button = new EntryButton(_panel, _eh->getList().at(i), x_pos);
		button->Show(true);
		_buttons.push_back(button);
		x_pos += 100;
	}
}

void Main::drawLines() {

}