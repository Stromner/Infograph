#include "ApplicationWindow.h"
#include <wx\frame.h>

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

ApplicationWindow::ApplicationWindow(){}

ApplicationWindow::~ApplicationWindow(){}


bool ApplicationWindow::OnInit() {
	wxFrame* mainFrame = new wxFrame(nullptr, wxID_ANY, L"MyProject");
	mainFrame->Show(true);
	return true;
}

wxIMPLEMENT_APP(ApplicationWindow);