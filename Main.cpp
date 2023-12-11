//#include "Hike.h"
//#include "HikeList.h"
//#include "Member.h"
//#include "MemberList.h"
//#include "Reservations.h"
#include "HikeReader.h"
#include "MemberReader.h"
#include "ReservationsReader.h"
#include "Interface.h"

#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	//// Test Hike object default constructor and insertion
	//cout << "\t*Hike insertion test*\n";
	//Hike myHike("Glacier", "Montana", 6, 's');
	//cout << myHike << endl;

	//Hike anotherHike("Doctor Strange", "Multiverse", 69, 'e');
	//cout << anotherHike << endl;

	//Hike emptyHike;
	//cout << emptyHike << endl;

	//Hike myOtherHike("Copy", "Montana", 4, 'm');
	//cout << myHike << endl;

	//// Test accessors
	//cout << "\t*Testing Hike Accessor functions*"
	//	<< "\n\t  Hike: " << myHike.getHike()
	//	<< "\n\t  Location: " << myHike.getLocation()
	//	<< "\n\t  Difficulty: " << myHike.getDifficulty()
	//	<< "\n\t  Duration: " << myHike.getDuration() << endl;
	//cout << endl; // spacing

	//// Test HikeList addHike
	//HikeList theHikeList;

	//theHikeList.addHike(myHike, 29.99);
	//theHikeList.addHike(myOtherHike, 59.99);
	//theHikeList.addHike(anotherHike, 6.77);
	//theHikeList.addHike("Best Hike", "My Anus", 69, 's', 69.69);
	//
	//cout << "\t*Print ALL locations*\n";
	//theHikeList.printAllLocations();
	//cout << endl;

	//cout << "\t*Print price*\n";
	//cout << "\t" << theHikeList.getPrice("Glacier") << "\n\n";

	//cout << "\t*Print by location*\n";
	//theHikeList.printByLocation("Montana");

	//cout << "\t*Print by duration*\n";
	//theHikeList.printByDuration();
	//cout << endl;

	//cout << "\t*Print by duration OVERLOAD*\n";
	//theHikeList.printByDuration(69);
	//cout << endl;

	//cout << "\t*Print by difficulty*\n";
	//theHikeList.printByDifficulty('s');
	//cout << endl;
	//theHikeList.printByDifficulty('e');
	//cout << endl;

	//cout << "\t*Print by price*\n";
	//theHikeList.printByPrice();
	//cout << endl;

	//cout << "\t*Print by name*\n";
	//theHikeList.printByHikeName("Glacier");
	//cout << endl;

	//theHikeList.clearList();
	//cout << "\t*Emptied List*\n";
	//theHikeList.printByHikeName("Glacier");
	//cout << "\tNothing was printed above\n";

	// // Test default constructor
	//cout << "\n\t*Testing print member*\n";
	//Member myMember("Gloria", "Mountain");
	//myMember.setID(423432);
	//myMember.addPoints(34);
	//myMember.addPoints(34);
	//myMember.printMember();

	//// Test accessors
	//cout << "\n\t*Testing Member Accessor functions*"
	//	<< "\n\t" << myMember.getPoints()
	//	<< "\n\t" << myMember.getLastName()
	//	<< "\n\t" << myMember.getIDNumber() << endl;

	//// Test MemberList
	//MemberList theMemberList;
	//theMemberList.addMember("Grandma", "Gatewood", 25876);
	//theMemberList.addMember("Kiran", "Sheikh");

	//cout << "\n\t*Testing Print functions*\n";
	//theMemberList.printMember(111, "Gatewood");
	//cout << endl;
	//theMemberList.printMember(112, "Sheikh");

	//cout << "\n\tGrandma's points: "
	//	<< theMemberList.getPoints(111) << endl;
	//cout << endl;


	// Main
	MemberList memberList;
	HikeList hikeList;
	Reservations reservations;

	getMemberData(memberList);
	getHikeData(hikeList);
	getReservationsData(reservations);

	displayMenu();
	processReservation(hikeList, memberList, reservations);

	return 0;
}