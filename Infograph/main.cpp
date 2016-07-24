#include "EntriesHandler.h"
#include <iostream>

void consoleCom(std::vector<std::shared_ptr<Entry>>);

#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <windows.h>

int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nCmdShow)
{
	AllocConsole();

	HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
	int hCrt = _open_osfhandle((long)handle_out, _O_TEXT);
	FILE* hf_out = _fdopen(hCrt, "w");
	setvbuf(hf_out, NULL, _IONBF, 1);
	*stdout = *hf_out;

	HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);
	hCrt = _open_osfhandle((long)handle_in, _O_TEXT);
	FILE* hf_in = _fdopen(hCrt, "r");
	setvbuf(hf_in, NULL, _IONBF, 128);
	*stdin = *hf_in;

	std::unique_ptr<EntriesHandler> eh(new EntriesHandler());
	eh->calculateTier();
	consoleCom(eh->getList());

	return 0;
}

int main() {
	std::unique_ptr<EntriesHandler> eh(new EntriesHandler());
	eh->calculateTier();
	consoleCom(eh->getList());
	
	return 0;
}

/*
Reads from the console as long as the input isn't '0'
*/
void consoleCom(std::vector<std::shared_ptr<Entry>> list) {
	std::cout << "Type 'debug' to get print. Input the name of the class that you want to unlock. Clear screen with \"cls\". Exit with \"0\"." << std::endl;
	std::string input;
	while (input.compare("0")) {
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