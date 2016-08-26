#include "Main.h"

wxIMPLEMENT_APP(Main);

bool Main::OnInit() {
	_frame = new wxFrame(NULL, wxID_ANY, "Infograph");
	_panel = new MainPanel(_frame);

	_frame ->Show(true);
	return true;
}