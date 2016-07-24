#include "Main.h"
#include <wx\frame.h>

wxIMPLEMENT_APP(Main);

Main::Main() {
	std::unique_ptr<EntriesHandler> eh(new EntriesHandler());
	eh->calculateTier();

	// Spawn new thread to run console in
	console_com = std::thread(&Main::consoleCom, this, eh->getList());
}

Main::~Main() {
	console_com.join();
}

bool Main::OnInit() {
	wxFrame* mainFrame = new wxFrame(nullptr, wxID_ANY, "Infograph");
	mainFrame->Show(true);
	return true;
}

/*
Reads from the console as long as the input isn't '0'
*/
void Main::consoleCom(std::vector<std::shared_ptr<Entry>> list) {
	std::cout << "Type 'debug' to get print. Input the name of the class that you want to unlock. Clear screen with \"cls\". Exit with \"0\"." << std::endl;
	std::string input;
	while (input.compare("0") && false) {
		std::cout << "Input: ";
		std::cin >> input;

		// Find the class
		for (unsigned int i = 0; i < list.size(); i++) {
			if (input.compare(list.at(i)->getName()) == 0) {
				list.at(i)->unlock();
			}
		}

		// Debug print
		if (input.compare("debug") == 0) {
			for (unsigned int i = 0; i < list.size(); i++) {
				std::cout << list.at(i)->toString() << std::endl;
			}
		}

		// Clear screen
		if (input.compare("cls") == 0) {
			system("cls");
		}
	}
}