#ifndef MAINPANEL_H
#define MAINPANEL_H
#pragma warning(disable : 4996)  // This removes the warning spam that wxwidgets creates

#include "EntriesHandler.h"
#include "EntryButton.h"
#include "wx\wx.h"

class MainPanel : public wxPanel{
public:
	MainPanel(wxFrame*);
	void paintEvent(wxPaintEvent &);
	void render(wxDC&);

	DECLARE_EVENT_TABLE()
private:
	void createButtons();

	std::unique_ptr<EntriesHandler> _eh;
	std::vector<EntryButton*> _buttons;
};

#endif