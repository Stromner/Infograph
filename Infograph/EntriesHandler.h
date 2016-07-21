/**
	Stores all entries in the program. Other than that it also solves what tier level the
	entries are at.
**/

#ifndef ENTRIESHANDLER_H
#define ENTRIESHANDLER_H

#include "Entry.h"

class EntriesHandler {
public:
	EntriesHandler(); // Reads all the entries from a file and input it into a list
	void calculateTier();
	std::vector<std::shared_ptr<Entry>> getList();
private:
	std::vector<std::shared_ptr<Entry>> _list;
};

#endif