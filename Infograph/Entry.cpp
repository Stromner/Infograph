#include "Entry.h"
#include <iostream>

Entry::Entry(std::string name):_name(name), _unlocked(false), _tier(-1){}

void Entry::initEntry(std::vector<std::shared_ptr<Entry>> requires,
	std::vector<std::shared_ptr<Entry>> unlocks)
{
	this->_requires = std::move(requires);
	this->_unlocks = std::move(unlocks);
}

std::string Entry::getName() {
	return _name;
}

bool Entry::isUnlocked() {
	return _unlocked;
}

void Entry::setTier(int tier) {
	_tier = tier;
}

int Entry::getTier() {
	return _tier;
}

std::vector<std::shared_ptr<Entry>> Entry::getRequires() {
	return _requires;
}

std::string Entry::requiredLeft() {
	std::string res = "";
	for (unsigned int i = 0; i < _requires.size(); i++) {
		if (!_requires.at(i)->isUnlocked()) {
			res += _requires.at(i)->getName() + ' ';
		}
	}

	return res;
}

bool Entry::unlock() {
	for (unsigned int i = 0; i < _requires.size(); i++) {
		if (_requires.at(i)->_unlocked == true) {
			continue;
		}
		else {
			std::cout << "Entry '" << _name << "' can't be unlocked yet." << std::endl;
			return false;
		}
	}

	if (!_unlocked) {
	std::cout << "Unlocked entry \"" << _name << "\"" << std::endl;
	_unlocked = true;
	}
	else {
		std::cout << "\"" << _name << "\" Is already unlocked" << std::endl;
	}

	return true;
}

std::string Entry::toString() {
	std::string res = _unlocked ? "true" : "false", res2="", res3="";
	for (unsigned int i = 0; i < _requires.size(); i++) {
		res2 += _requires.at(i)->getName() + ' ';
	}
	for (unsigned int i = 0; i < _unlocks.size(); i++) {
		res3 += _unlocks.at(i)->getName() + ' ';
	}
	return "Name: "		+ _name	+
		"\n Unlocked: "	+ res	+
		"\n Requires: " + res2	+
		"\n Unlocks: "	+ res3	+
		"\n Tier: "		+ std::to_string(_tier);
}