#ifndef HIKELIST_H
#define HIKELIST_H

#include "Hike.h"

#include <string>
#include <map>

class HikeList 
{
public:
	HikeList() {}

	void addHike(const Hike& aHike, double aPrice);
	void addHike(const std::string& aLocation,
		const std::string& aHikeName, int aDuration,
		char aDifficulty, double aPrice);

	double getPrice(const std::string& theHikeName) const;

	void printAllLocations() const;
	void printByLocation(const std::string& aLocation) const;
	void printByDuration() const;
	void printByDuration(int aDuration) const;
	void printByDifficulty(char aDifficulty) const;
	void printByPrice() const;
	void printByHikeName(const std::string& theHikeName) const;

	void clearList();

	~HikeList() {}

private:
	std::multimap<Hike, double> myMultiMap;
};

#endif