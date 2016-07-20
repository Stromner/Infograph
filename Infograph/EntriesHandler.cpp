#pragma warning(push)
#pragma warning( disable : 4996)
#include "EntriesHandler.h"
#include <iostream>
#include <fstream>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

/**
Reads graph data from Data.txt, the data is used to create the objects and their requires
and unlocks lists.

Once the data is constructed main loops for input until '0' is entered. Input is the name
of the objects that main should unlock.
**/
EntriesHandler::EntriesHandler() {
	std::vector<std::shared_ptr<Entry>> list;
	std::ifstream infile("Data.txt");
	std::string line;

	// Create empty entries
	while (std::getline(infile, line)) {
		if (line.at(0) == '#') {
			std::cout << "Comment line read, skipping line." << std::endl;
		}
		else {
			std::vector<std::string> data;
			boost::split(data, line, boost::is_any_of("\t"), boost::token_compress_on);
			std::unique_ptr<Entry> ptr(new Entry(data.at(0)));
			list.push_back(std::move(ptr));
		}
	}

	// Create requires and unlocks list for all entries
	infile.close();
	infile.open("Data.txt");
	while (std::getline(infile, line)) {
		if (line.at(0) == '#') {
			std::cout << "Comment line read, skipping line." << std::endl;
		}
		else {
			std::vector<std::string> data, data_new;
			std::vector<std::shared_ptr<Entry>> requires;
			std::vector<std::shared_ptr<Entry>> unlocks;

			boost::split(data, line, boost::is_any_of("\t"), boost::token_compress_on);
			boost::split(data_new, data.at(1), boost::is_any_of(","), boost::token_compress_on);
			// Find the entries that are listed as requires
			for (unsigned int i = 0; i < data_new.size(); i++) {
				for (unsigned int j = 0; j < list.size(); j++) {
					if (list.at(j)->getName().compare(data_new.at(i)) == 0) {
						requires.push_back(list.at(j));
					}
				}
			}

			// Find the entries that are listed as unlocks
			boost::split(data_new, data.at(2), boost::is_any_of(","), boost::token_compress_on);
			for (unsigned int i = 0; i < data_new.size(); i++) {
				for (unsigned int j = 0; j < list.size(); j++) {
					if (list.at(j)->getName().compare(data_new.at(i)) == 0) {
						unlocks.push_back(list.at(j));
					}
				}
			}

			// Find the element that have these lists
			for (unsigned int i = 0; i < list.size(); i++) {
				if (list.at(i)->getName().compare(data.at(0)) == 0) {
					list.at(i)->initEntry(requires, unlocks);
					std::cout << "Created entity \"" << list.at(i)->getName() << "\"" << std::endl;
				}
			}
		}
	}
	infile.close();
}

std::vector<std::shared_ptr<Entry>> EntriesHandler::getList() {
	return _list;
}
#pragma warning( pop )  