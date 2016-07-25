#pragma warning(push)
#pragma warning( disable : 4996)
#include "EntriesHandler.h"
#include <iostream>
#include <fstream>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

bool tier_key(std::shared_ptr<Entry>, std::shared_ptr<Entry>);

/**
Reads graph data from Data.txt, the data is used to create the objects and their requires
and unlocks lists.

Once the data is constructed main loops for input until '0' is entered. Input is the name
of the objects that main should unlock.
**/
EntriesHandler::EntriesHandler() {
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
			_list.push_back(std::move(ptr));
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
				for (unsigned int j = 0; j < _list.size(); j++) {
					if (_list.at(j)->getName().compare(data_new.at(i)) == 0) {
						requires.push_back(_list.at(j));
					}
				}
			}

			// Find the entries that are listed as unlocks
			boost::split(data_new, data.at(2), boost::is_any_of(","), boost::token_compress_on);
			for (unsigned int i = 0; i < data_new.size(); i++) {
				for (unsigned int j = 0; j < _list.size(); j++) {
					if (_list.at(j)->getName().compare(data_new.at(i)) == 0) {
						unlocks.push_back(_list.at(j));
					}
				}
			}

			// Find the element that have these lists
			for (unsigned int i = 0; i < _list.size(); i++) {
				if (_list.at(i)->getName().compare(data.at(0)) == 0) {
					_list.at(i)->initEntry(requires, unlocks);
					std::cout << "Created entity \"" << _list.at(i)->getName() << "\"" << std::endl;
				}
			}
		}
	}
	infile.close();
}

void EntriesHandler::calculateTier() {
	int current_tier = 0;

	// Find the entities that are going to be the base. These enteties are defined as the
	// require list is empty
	for (unsigned int i = 0; i < _list.size();i++) {
		if (_list.at(i)->getRequires().empty()) {
			_list.at(i)->setTier(0);
		}
	}

	// Calculate the remaining entries off the base entries. An entry's tier needs the require 
	// list to have all defined values (i.e no '-1' values) and requires that are less than
	// the current tier that's being calculated.
	while (continueCalculate()) {
		for (unsigned int i = 0; i < _list.size(); i++) {
			bool is_current_tier = true;
			for (unsigned int j = 0; j < _list.at(i)->getRequires().size(); j++) {
				if (_list.at(i)->getRequires().at(j)->getTier() >= current_tier || _list.at(i)->getRequires().at(j)->getTier() == -1) {
					is_current_tier = false;
				}
			}
			if (is_current_tier && _list.at(i)->getTier() == -1) {
				_list.at(i)->setTier(current_tier);
			}
		}

		current_tier += 1;
	}

	std::sort(_list.begin(), _list.end(), tier_key);
}

std::vector<std::shared_ptr<Entry>> EntriesHandler::getList() {
	return _list;
}

bool EntriesHandler::continueCalculate() {
	for (unsigned int i = 0; i < _list.size(); i++) {
		if (_list.at(i)->getTier() == -1) {
			return true;
		}
	}
	return false;
}

bool tier_key(std::shared_ptr<Entry> e1, std::shared_ptr<Entry> e2) {
	return (e1->getTier() < e2->getTier());
}

#pragma warning( pop )  