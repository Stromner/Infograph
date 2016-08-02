#include <wx\app.h>
#include <wx\frame.h>
#include <wx\panel.h>
#include "EntriesHandler.h"
#include "EntryButton.h"

#ifdef _UNICODE
#ifdef _DEBUG
#pragma comment(lib, "wxbase31ud.lib")
#else
#pragma comment(lib, "wxbase31u.lib")
#endif
#else
#ifdef _DEBUG
#pragma comment(lib, "wxbase31d.lib")
#else
#pragma comment(lib, "wxbase31.lib")
#endif
#endif

#ifndef MAIN_H
#define MAIN_H

class Main : public wxApp{
public:
	virtual bool OnInit() override;
private:
	void createButtons();
	void drawLines();
	wxPanel * _panel;
	std::unique_ptr<EntriesHandler> _eh;
	std::vector<EntryButton*> _buttons;
};

#endif