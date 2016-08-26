#include "MainPanel.h"

BEGIN_EVENT_TABLE(MainPanel, wxPanel)
EVT_PAINT(MainPanel::paintEvent) // catch paint events
END_EVENT_TABLE()

MainPanel::MainPanel(wxFrame* parent) : wxPanel(parent, wxID_ANY){
	_eh.reset(new EntriesHandler());
	_eh->calculateTier();
	
	createButtons();
}

void MainPanel::paintEvent(wxPaintEvent& evt){
	wxPaintDC dc(this);
	render(dc);
}

void MainPanel::createButtons() {
	int x_pos = 0, tier = 0;
	for (unsigned int i = 0; i < _eh->getList().size(); i++) {
		if (tier < _eh->getList().at(i)->getTier()) {
			tier++;
			x_pos = 0;
		}

		EntryButton* button = new EntryButton(this, _eh->getList().at(i), x_pos);
		button->Show(true);
		_buttons.push_back(button);
		x_pos += 100;
	}
}

void MainPanel::render(wxDC&  dc){
	// Draw the arrows here
}