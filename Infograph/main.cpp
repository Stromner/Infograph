#include "EntriesHandler.h"
#include <iostream>

void consoleCom(std::vector<std::shared_ptr<Entry>>);

int main() {
	std::unique_ptr<EntriesHandler> eh(new EntriesHandler());
	consoleCom(eh->getList());

	return 0;
}

/*
Reads from the console as long as the input isn't '0'
*/
void consoleCom(std::vector<std::shared_ptr<Entry>> list) {
	std::cout << "Type 'debug' to get print. Input the name of the class that you want to unlock. Clear screen with \"cls\"" << std::endl;
	std::string input;
	while (input.compare("0")) {
		std::cout << "Input: ";
		std::cin >> input;

		// Find the class
		for (int i = 0; i < list.size(); i++) {
			if (input.compare(list.at(i)->getName()) == 0) {
				list.at(i)->unlock();
			}
		}

		// Debug print
		if (input.compare("debug") == 0) {
			for (int i = 0; i < list.size(); i++) {
				std::cout << list.at(i)->toString() << std::endl;
			}
		}

		// Clear screen

		// Debug print
		if (input.compare("cls") == 0) {
			system("cls");
		}
	}
}