#include "EntryButton.h"
#include <wx/wxprec.h>

EntryButton::EntryButton(wxPanel *panel, std::shared_ptr<Entry> e, int x_pos) : wxToggleButton(panel, ID_Pressed, e->getName(), wxPoint(e->getTier()*Y_CORD_BUTTON_SPACING_VAR, x_pos)) {
	_entry = e;
	Connect(ID_Pressed, wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(EntryButton::onPressed));
}

void EntryButton::onPressed(wxCommandEvent& event) {
	if (_entry->unlock()) {
		SetValue(true);
	}
	else {
		SetValue(false);
		std::string s = "Can't unlock yet! \nNeed to unlock following entries first:\n";
		s += _entry->requiredLeft();
		char * c_s = new char[s.size() + 1];
		std::copy(s.begin(), s.end(), c_s);
		c_s[s.size()] = '\0';
		wxLogMessage(c_s);
	}
}