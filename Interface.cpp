#include "Interface.h"

#include <iostream>
#include <iomanip>

using namespace std;

void displayMenu() 
{
    cout <<
        "***************************************************\n"
        << "\t\tHIKING IN THE US\n" <<
        "***************************************************\n\n"
        << "\t1. Browse by location\n"
        << "\t2. Browse by duration\n"
        << "\t3. Browse by difficulty\n"
        << "\t4. Browse by price\n"
        << "\t5. Make a reservation\n"
        << "\t6. View reservation\n"
        << "\t7. Cancel reservation\n"
        << "\t8. Rate a Trail\n"
        << "\t9. Exit\n";
}

void processReservation(HikeList& hikeListObj, 
    MemberList& memberListObj,
    Reservations& reservationsObj)
{
    char memberInput = '0';
    bool programComplete = false;

    while (!programComplete)
    {
        cout << "\nPlease make a selection: ";
        cin >> memberInput;

        if (memberInput == '1')
        {
            chooseByLocation(hikeListObj, memberListObj, 
                reservationsObj);
        }
        else if (memberInput == '2')
        {
            chooseByDuration(hikeListObj, memberListObj, 
                reservationsObj);
        }
        else if (memberInput == '3')
        {
            chooseByDifficulty(hikeListObj, memberListObj, 
                reservationsObj);
        }
        else if (memberInput == '4')
        {
            chooseByPrice(hikeListObj, memberListObj, 
                reservationsObj);
        }
        else if (memberInput == '5')
        {
            makeReservation(hikeListObj, memberListObj, 
                reservationsObj);
        }
        else if (memberInput == '6')
        {
            viewReservation(hikeListObj, memberListObj, 
                reservationsObj);
        }
        else if (memberInput == '7')
        {
            cancelReservation(hikeListObj, memberListObj, 
                reservationsObj);
        }
        else if (memberInput == '8')
        {
            cout << "\nThank you for visiting!\n";
            programComplete = true;
        }

        cout << "\n";
        system("Pause");
        cout << "\n";
        displayMenu();
    }
}

void chooseByLocation(HikeList& hikeListObj, 
    MemberList& memberListObj,
    Reservations& reservationsObj)
{
    cout << "\n";
    hikeListObj.printAllLocations();

    cout << "\nChoose a location: ";
    string location;
    cin >> location;

    cout << "\n";
    hikeListObj.printByLocation(location);
    askToReserve(hikeListObj, memberListObj, reservationsObj);
}

void chooseByDuration(HikeList& hikeListObj, 
    MemberList& memberListObj,
    Reservations& reservationsObj)
{
    cout << "\n\t(days)\n";
    hikeListObj.printByDuration();
    cout << "\nHow many days are you considering: ";
    int durationDays = 0;
    cin >> durationDays;

    cout << "\n";
    hikeListObj.printByDuration(durationDays);
    askToReserve(hikeListObj, memberListObj, reservationsObj);
}

void chooseByDifficulty(HikeList& hikeListObj, 
    MemberList& memberListObj,
    Reservations& reservationsObj)
{
    cout << "\nChoose difficulty level: \n\n"
        << "           e. easy\n"
        << "           m. moderate\n"
        << "           s. strenous\n\n"
        << "Your choice: ";

    char choice = 'a';
    cin >> choice;

    cout << "\n";
    hikeListObj.printByDifficulty(choice);
    cout << "\n";
    askToReserve(hikeListObj, memberListObj, reservationsObj);
}

void chooseByPrice(HikeList& hikeListObj, MemberList& memberListObj,
    Reservations& reservationsObj)
{
    cout << "\n";
    hikeListObj.printByPrice();
    cout << "\n";
    askToReserve(hikeListObj, memberListObj, reservationsObj);

}

int askIfMember(MemberList& memberListObj)
{
    char yesOrNo = 'y';
    cout << "\nAre you a member? (y/n) ";
    cin >> yesOrNo;
    int memberiD = 0;
    if (yesOrNo == 'y')
    {
        cout << "\nWhat is your member ID number? ";
        cin >> memberiD;
        string lastName;
        cout << "\nWhat is your last name? ";
        cin >> lastName;
        cout << "\n";
        memberListObj.printMember(memberiD, lastName);
        return memberiD;
    }
    else
    {
        return addNewMember(memberListObj);
    }
}

int addNewMember(MemberList& memberListObj)
{
    cout << "\n\tLet's add you to the member list!"
        << "\n\t\tWhat is your first name? ";
    std::string firstName;
    cin >> firstName;

    cout << "\t\tWhat is your last name? ";
    std::string lastName;
    cin >> lastName;

    memberListObj.addMember(firstName, lastName);
    cout << "\n\tWelcome to the club!"
        << "\n\t\tYour member ID number is: " 
        << memberListObj.getLastID() << "\n";

    return memberListObj.getLastID();
}

void makeReservation(HikeList& hikeListObj, 
    MemberList& memberListObj,
    Reservations& reservationsObj)
{
    int theirMemberiD = askIfMember(memberListObj);

    string hikeName;
    cout << "\nWhich hike would you like to reserve (hike name)? ";
    cin >> hikeName;

    int reservationNumber = 
        reservationsObj.addReservation(theirMemberiD, hikeName);

    reservationsObj.printReservation(reservationNumber,
        hikeListObj, memberListObj);

    cout << "\n\tBefore proceeding, "
        << "please make a note of your reservation number."
        << "\n\t  Reservation #: " << reservationNumber
        << "\n\n( *** Will continue to scheduling and payment. *** )"
        << "\n";
}

void viewReservation(HikeList& hikeListObj, 
    MemberList& memberListObj, Reservations& reservationsObj)
{
    int resNumber = 0;
    cout << "\nEnter reservation #: ";
    cin >> resNumber;

    reservationsObj.printReservation(resNumber, hikeListObj, 
        memberListObj);
}

void cancelReservation(HikeList& hikeListObj, 
    MemberList& memberListObj,
    Reservations& reservationsObj)
{
    int resNumber = 0;
    cout << "\nEnter reservation #: ";
    cin >> resNumber;

    reservationsObj.printReservation(resNumber, hikeListObj, 
        memberListObj);

    cout << '\n';
    char yesOrNo = 'y';
    cout << "Are you sure you want to cancel this reservation?"
        << " (y/n) ";
    cin >> yesOrNo;
    if (yesOrNo == 'y')
    {
        reservationsObj.cancelReservation(resNumber);
        cout << "\nReservation #" << resNumber 
            << " has been canceled.\n";
    }
}

void askToReserve(HikeList& hikeListObj, MemberList& memberListObj,
    Reservations& reservationsObj)
{
    char yesOrNo = 'y';
    cout << "Would you like to make a reservation? (y/n) ";
    cin >> yesOrNo;

    if (yesOrNo == 'y')
    {
        makeReservation(hikeListObj, memberListObj, reservationsObj);
    }
}
