#include <wx\app.h>
#include "EntriesHandler.h"
#include <iostream>

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

class Main : public wxApp{
public:
	Main();
	virtual bool OnInit() override;
private:
	std::shared_ptr<EntriesHandler> _eh;
};

