#include <wx\button.h>
#include <wx\panel.h>
#include "Entry.h"

#ifndef ENTRYBUTTON_H
#define ENTRYBUTTON_H

const int Y_CORD_BUTTON_SPACING_VAR = 150;

class EntryButton : public wxButton {
public:
	EntryButton(wxPanel *, std::shared_ptr<Entry>, int);
private:
	std::shared_ptr<Entry> _entry;
};

#endif