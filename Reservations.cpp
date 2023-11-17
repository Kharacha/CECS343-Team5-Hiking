#include "Interface.h"

#include <iostream>
#include <iomanip>

using namespace std;

int Reservations::addReservation(int aMemberID, string& aHikeName)
{
    int reservationNumber = RESERVATION_NUMBER;

    if (count == 0)
    {
        first = last = new Node(reservationNumber, aMemberID,
            aHikeName, nullptr, nullptr);
    }
    else
    {
        reservationNumber += count;

        last = new Node(reservationNumber, aMemberID,
            aHikeName, nullptr, last);
        last->getPrev()->setNext(last);
    }

    ++count;

    return reservationNumber;                                                                                                
}

void Reservations::cancelReservation(int aReservationNumber)
{
    if (count == 1)
    {
        delete first;
        first = last = nullptr;
    }
    else
    {
        Node* temp = findReservation(aReservationNumber);

        if (temp == first)
        {
            first = first->getNext();
            first->setPrev(nullptr);
        }
        else if (temp == last)
        {
            last = last->getPrev();
            last->setNext(nullptr);
        }
        else
        {
            temp->getPrev()->setNext(temp->getNext());
            temp->getNext()->setPrev(temp->getPrev());
        }

        delete temp;
        temp = nullptr;
    }
}

void Reservations::printReservation(int aReservationNumber, 
    const HikeList& aHikeList,
    const MemberList& aMemberList) const
{
    Node* current = findReservation(aReservationNumber);

    if (current != nullptr)
    {
        string hikeName = current->getHikeName();

        aHikeList.printByHikeName(hikeName);

        int points = aMemberList.getPoints(current->getMemberID());
        double price = aHikeList.getPrice(current->getHikeName());
        double discountedPrice = price - (points / 100);

        if (points > 99)
        {
            cout << "\n\tDiscounted price using points: $"
                << fixed << setprecision(2) << discountedPrice
                << "\n";
        }
    }
    else
    {
        cout << "\nThis reservation does not exist." << "\n"; 
    }
}

void Reservations::clearList()
{
    while (first != last)
    {
        first = first->getNext();
        delete first->getPrev();
    }

    delete first;
    last = nullptr;
    count = 0;
}

Reservations::~Reservations()
{
    clearList();
}


Node* Reservations::findReservation(int aReservationNumber) const
{
    Node* current = first;

    while (current != nullptr)
    {
        if (current->getReservationNumber() == aReservationNumber)
        {
            return current;
        }

        current = current->getNext();
    }

    return current;
}