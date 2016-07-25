#include "Main.h"
#include <wx\frame.h>

wxIMPLEMENT_APP(Main);

Main::Main() {
	std::unique_ptr<EntriesHandler> eh(new EntriesHandler());
	eh->calculateTier();
}

bool Main::OnInit() {
	wxFrame* mainFrame = new wxFrame(nullptr, wxID_ANY, "Infograph");
	mainFrame->Show(true);
	return true;
}