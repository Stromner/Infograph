/**
	An entry defines an element that contains some sort of information, these entries are
	read from a .txt file that can easily be modified by outside users to create the own 
	info-graphs. Each entry got two optional lists that are the following:
	requires - Says what entries are needed for this entry to be available.
	unlocks - Says what entries this entry contributes to.
**/

#ifndef ENTRY_H
#define ENTRY_H

#include <list>
#include <memory>
#include <string>
#include <vector>

class Entry {
public:
	Entry(std::string);
	void initEntry(std::vector<std::shared_ptr<Entry>> ,
		std::vector<std::shared_ptr<Entry>> );
	std::string getName();
	void setTier(int);
	int getTier();
	std::vector<std::shared_ptr<Entry>> getRequires();
	bool unlock(); // Unlock this entry if requires is fulfilled.
	std::string toString();
private:
	bool _unlocked;
	std::vector<std::shared_ptr<Entry>> _requires;
	std::vector<std::shared_ptr<Entry>> _unlocks;
	std::string _name;
	int _tier;
};

#endif
