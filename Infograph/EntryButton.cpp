#include "EntryButton.h"

EntryButton::EntryButton(wxPanel *panel, std::shared_ptr<Entry> e, int x_pos) : wxButton(panel, wxID_ANY, e->getName(), wxPoint(e->getTier()*Y_CORD_BUTTON_SPACING_VAR, x_pos)) {
	_entry = e;
}