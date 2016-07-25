#include "Main.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(Main);

Main::Main() {
	_eh.reset(new EntriesHandler());
	_eh->calculateTier();
}

bool Main::OnInit() {
	wxFrame* mainFrame = new MainFrame("Infograph", _eh);
	mainFrame->Show(true);

	return true;
}