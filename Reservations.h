#ifndef RESERVATIONS_H
#define RESERVATIONS_H

#include "HikeList.h"
#include "MemberList.h"

#include <string>

const int RESERVATION_NUMBER = 50001;

class Node
{
public:
	Node() : reservationNumber(0), memberID(0),
		next(nullptr), prev(nullptr) {}

	Node(int aReservationNumber, int aMemberID,
		const std::string& aHikeName, Node* theNext, Node* thePrev)
		: reservationNumber(aReservationNumber),
		memberID(aMemberID), hikeName(aHikeName), next(theNext),
		prev(thePrev) {}

	int getReservationNumber() const { return reservationNumber;  }
	int getMemberID() const { return memberID;  }
	std::string getHikeName() const { return hikeName;  }
	Node* getNext() const { return next; }
	Node* getPrev() const { return prev; }

	void setReservationNumber(int aReservationNumber) 
		{ reservationNumber = aReservationNumber; }
	void setMemberID(int aMemberID) { memberID = aMemberID; }
	void setHikeName(std::string aHikeName) { hikeName = aHikeName; }
	void setPrev(Node* thePrev) { prev = thePrev; }
	void setNext(Node* theNext) { next = theNext; }
	
	~Node() {}

private:
	int reservationNumber;
	int memberID;
	std::string hikeName;
	Node* prev;
	Node* next;
};

class Reservations
{
public:
	Reservations() : first(nullptr), last(nullptr), count(0) {}

	int addReservation(int aMemberID, std::string& aHikeName);
	void cancelReservation(int aReservationNumber);
	
	void printReservation(int aReservationNumber, 
		const HikeList& aHikeList, 
		const MemberList& aMemberList) const;

	void clearList();
	~Reservations();

private:
	Node* findReservation(int aReservationNumber) const;
	Node* first;
	Node* last;
	int count;
};

#endif