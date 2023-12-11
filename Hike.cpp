#include "Hike.h"

#include <iostream>
#include <string>

using namespace std;

ostream& operator<<(ostream& out, const Hike& aHike)
{
	out << "\t" << aHike.hike << " ("
		<< aHike.location << ")\n"
		<< "\t  Difficulty: ";

	if (aHike.difficulty == 'e')
		out << "easy\n";
	else if (aHike.difficulty == 'm')
		out << "moderate\n";
	else if (aHike.difficulty == 's')
		out << "strenuous\n";

	out << "\t  Duration: " << aHike.duration
		<< " day(s)\n";

	return out;
}

string Hike::getLocation() const
{
	return location;
}

int Hike::getDuration() const
{
	return duration;
}

char Hike::getDifficulty() const
{
	return difficulty;
}

std::string Hike::getHike() const
{
	return hike;
}

bool Hike::operator<(const Hike& aHike) const
{
	return (location < aHike.location);
}