#include "Member.h"

#include <iostream>
#include <iomanip>

using namespace std;

void Member::addPoints(int addPoint)
{
    storePoint += addPoint;
}

void Member::setID(int newMemberID)
{
    memberID = newMemberID;
}

int Member::getIDNumber() const
{
    return memberID;
}

string Member::getLastName() const
{
    return lastName;
}

int Member::getPoints() const
{
    return storePoint;
}

bool Member::operator<(const Member& aMember) const
{
    return memberID < aMember.memberID;
} 

void Member::printMember() const
{
    cout << "\t" << lastName << ", " << firstName 
        << "\n\tPoints available: " << storePoint << "\n";
}