#ifndef HIKE_H
#define HIKE_H

#include <iostream>
#include <string>

class Hike
{
	friend std::ostream& operator<<(std::ostream&, const Hike& aHike);

public:
	Hike() : duration(0), difficulty('e') {}
	Hike(const std::string& aHike, const std::string& aLocation,
		int theDuration, char theDifficulty) :
		location(aLocation), hike(aHike), duration(theDuration),
		difficulty(theDifficulty) {}

	std::string getLocation() const;
	int getDuration() const;
	char getDifficulty() const;
	std::string getHike() const;

	bool operator<(const Hike& aHike) const;

	~Hike() {}

private:
	std::string location;
	std::string hike;
	int duration;
	char difficulty;
};

#endif
