#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member
{
public:
    Member() : memberID(0), storePoint(0) {}
    Member(const std::string& aFirstName, 
        const std::string& aLastName) :
        firstName(aFirstName), lastName(aLastName), memberID(0),
        storePoint(0) {}

    void addPoints(int addPoint);
    void setID(int newMemberID);

    int getIDNumber() const;
    std::string getLastName() const;
    int getPoints() const;

    bool operator<(const Member& aMember) const;

    void printMember() const;

    ~Member() {}

private:

    int memberID;
    std::string firstName;
    std::string lastName;
    int storePoint;
};

#endif