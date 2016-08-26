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

#include <wx\app.h>
#include <wx\frame.h>
#include "MainPanel.h"

class Main : public wxApp{
public:
	virtual bool OnInit() override;
private:
	wxFrame* _frame;
	MainPanel* _panel;
};

#endif