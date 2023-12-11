#include "MemberList.h"

#include <iostream>
#include <algorithm>

using namespace std;

MemberList::MemberList()
{
    memberSet = new set<Member>;
}

void MemberList::addMember(const string& firstName,
    const string& lastName)
{
    int newID = MEMBER_ID;

    if (! memberSet->empty())
    {
        newID += static_cast<int>(memberSet->size());
    }
    
    Member newMember(firstName, lastName);
    newMember.setID(newID);
    memberSet->insert(newMember);
}

void MemberList::addMember(const string& firstName, 
    const string& lastName, int points)
{
    int newID = MEMBER_ID;

    if (!memberSet->empty())
    {
        newID += static_cast<int>(memberSet->size());
    }

    Member newMember(firstName, lastName);
    newMember.setID(newID);
    newMember.addPoints(points);
    memberSet->insert(newMember);
}

int MemberList::getLastID() const
{
    return (memberSet->rbegin())->getIDNumber();
}

int MemberList::getPoints(int memberID) const
{
    auto listIter = find_if(memberSet->begin(), memberSet->end(),
        [&](const auto& theMember) { return
        (theMember.getIDNumber() == memberID); });

    return listIter->getPoints();
}

void MemberList::printMember(int memberID, 
    const std::string& lastName) const
{
    auto listIter = find_if(memberSet->begin(), memberSet->end(),
        [&](const auto& theMember) { return
        (theMember.getIDNumber() == memberID); });

    if ((listIter->getLastName() == lastName)
        && (listIter != memberSet->end()))
    {
        listIter->printMember();

        cout << "\tMembership # " << memberID << "\n";
    }
}

void MemberList::clearList()
{
    memberSet->clear();
}

MemberList::~MemberList() 
{
    delete memberSet;
    memberSet = nullptr;
}