#include <wx\app.h>

class ApplicationWindow : public wxApp{
public:
	ApplicationWindow();
	virtual ~ApplicationWindow();
	virtual bool OnInit() override;
};

