#include "HikeList.h"

#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

void HikeList::addHike(const Hike& aHike, double aPrice)
{
    myMultiMap.insert(make_pair(aHike, aPrice));
}

void HikeList::addHike(const string& aLocation, const string& theHikeName,
    int aDuration, char aDifficulty, double aPrice)
{
    Hike newHike(aLocation, theHikeName, aDuration, aDifficulty);
    myMultiMap.insert(make_pair(newHike, aPrice));
}

double HikeList::getPrice(const string& theHikeName) const
{
    auto multiIter = find_if(myMultiMap.begin(), myMultiMap.end(),
        [&theHikeName](const auto& aPair)
        { return (theHikeName == (aPair.first).getHike()); }
    );

    return multiIter->second;
}

void HikeList::printAllLocations() const
{
    auto multiIter = myMultiMap.begin();

    while (multiIter != myMultiMap.end())
    {
        cout << "\t" << (multiIter->first).getLocation() << "\n";

        multiIter = myMultiMap.upper_bound(multiIter->first);
    }
}

void HikeList::printByLocation(const string& aLocation) const
{
    auto multiIter = find_if(myMultiMap.begin(), myMultiMap.end(),
        [&aLocation](const auto& aPair)
        { return (aPair.first).getLocation() == aLocation; });

    while ((multiIter != myMultiMap.end())
        && ((multiIter->first).getLocation() == aLocation))
    {
        cout << multiIter->first
            << "\t  Price (per person): $ " << fixed 
            << setprecision(2) << multiIter->second << "\n\n";
        ++multiIter;
    }
}

void HikeList::printByDuration() const
{
    //multimap<int, string> tempMulti;

    multimap<int, pair<string, string>> tempMulti;

    //for (const auto& aPair : myMultiMap)
    //{
    //    tempMulti.insert(make_pair(
    //        (aPair.first).getDuration(),
    //        (aPair.first).getLocation()));
    //}

    //for_each(tempMulti.begin(), tempMulti.end(),
    //    [](const auto& aPair) {
    //        cout << "\t(" << aPair.first
    //            << ") " << aPair.second << endl; });

    for (const auto& aPair : myMultiMap)
    {
        tempMulti.insert(make_pair((aPair.first).getDuration(), 
            (make_pair((aPair.first).getHike(), 
                (aPair.first).getLocation()))));
    }

    for_each(tempMulti.begin(), tempMulti.end(),
        [](const auto& aPair) {
            cout << "\t(" << aPair.first
                << ") " << (aPair.second).first << ", "
                << (aPair.second).second << endl; });

}

void HikeList::printByDuration(int aDuration) const
{
    for (const auto& aPair : myMultiMap)
    {
        if ((aPair.first).getDuration() == aDuration)
        {
            cout << aPair.first << "\n";
        }
    }
}

void HikeList::printByDifficulty(char aDifficulty) const
{
    cout << "\t(difficulty level)\n";

    for (const auto& aPair : myMultiMap)
    {
        if ((aPair.first).getDifficulty() == aDifficulty)
        {
            cout << "\t(" << aDifficulty << ") "
                << (aPair.first).getHike() << ", "
                << (aPair.first).getLocation() << "\n";
        }
    }
}

void HikeList::printByPrice() const
{
    multimap<double, pair<string, string>> tempMulti;

    for (const auto& aPair : myMultiMap)
    {
        tempMulti.emplace(aPair.second, make_pair(
            (aPair.first).getLocation(),
            (aPair.first).getHike()));
    }

    for (const auto& aPair : tempMulti)
    {
        cout << "\t$ " << fixed << setprecision(2)
            << setw(7) << aPair.first << " - " <<
            (aPair.second).first << " (" << (aPair.second).second
            << ")\n";
    }
}

void HikeList::printByHikeName(const string& theHikeName) const
{
    auto multiIter = find_if(myMultiMap.begin(), myMultiMap.end(),
        [&](const auto& aPair)
        { return (aPair.first).getHike() == theHikeName; });

    if (multiIter != myMultiMap.end())
    {
        cout << "\n" << multiIter->first
            << "\t  $" << fixed << setprecision(2)
            << multiIter->second << "\n";
    }
}

void HikeList::clearList()
{
    myMultiMap.clear();
}