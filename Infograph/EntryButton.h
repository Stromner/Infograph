#include <wx\tglbtn.h>
#include <wx\panel.h>
#include "Entry.h"

#ifndef ENTRYBUTTON_H
#define ENTRYBUTTON_H

const int Y_CORD_BUTTON_SPACING_VAR = 150;

enum {
	ID_Pressed = 1
};

class EntryButton : public wxToggleButton {
public:
	EntryButton(wxPanel *, std::shared_ptr<Entry>, int);
private:
	void onPressed(wxCommandEvent&);
	std::shared_ptr<Entry> _entry;
};

#endif