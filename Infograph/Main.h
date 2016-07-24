#include <wx\app.h>
#include "EntriesHandler.h"
#include <iostream>
#include <thread> 

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
	~Main();
	virtual bool OnInit() override;
private:
	void consoleCom(std::vector<std::shared_ptr<Entry>>);
	std::thread console_com;
};

