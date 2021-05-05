/*
 */


#include <stdio.h>
#include "MMAFighters.h"
using namespace std;


//Default Constructor
MMAFighters::MMAFighters()
{
    fighterNumber = " ";
    firstName = " ";
    lastName = " ";
    nickName = " ";
    height = " ";
    weight = " ";
    reach = " ";
    stance = " ";
    record = " ";
    wins = " ";
    losses = " ";
    draws = " ";
    totalFights = " ";
}

//Mutator functions
void MMAFighters::setFighterNumber(string _fighterNumber)
{
    fighterNumber = _fighterNumber;
}
void MMAFighters::setFirstName(string _firstName)
{
    firstName = _firstName;
}
void MMAFighters::setNickName(string _nickName)
{
    nickName = _nickName;
}
void MMAFighters::setLastName(string _lastName)
{
    lastName = _lastName;
}
void MMAFighters::setHeight(string _height)
{
    height = _height;
}
void MMAFighters::setWeight(string _weight)
{
    weight  = _weight;
}
void MMAFighters::setReach(string _reach)
{
    reach = _reach;
}
void MMAFighters::setStance(string _stance)
{
    stance = _stance;
}
void MMAFighters::setRecord(string _record)
{
    record = _record;
}
void MMAFighters::setWins(string _wins)
{
    wins = _wins;
}
void MMAFighters::setLosses(string _losses)
{
    losses = _losses;
}
void MMAFighters::setDraws(string _draws)
{
    draws = _draws;
}
void MMAFighters::setTotalFights(string _totalFights)
{
    totalFights = _totalFights;
}


//Accessor functions
string MMAFighters::getFighterNumber()
{
    return fighterNumber;
}
string MMAFighters::getFirstName()
{
    return firstName;
}
string MMAFighters::getNickName()
{
    return nickName;
}
string MMAFighters::getLastName()
{
    return lastName;
}
string MMAFighters::getHeight()
{
    return height;
}
string MMAFighters::getWeight()
{
    return weight;
}
string MMAFighters::getReach()
{
    return reach;
}
string MMAFighters::getStance()
{
    return stance;
}
string MMAFighters::getRecord()
{
    return record;
}
string MMAFighters::getWins()
{
    return wins;
}
string MMAFighters::getLosses()
{
    return losses;
}
string MMAFighters::getDraws()
{
    return draws;
}
string MMAFighters::getTotalFights()
{
    return totalFights;
}

//Overloaded << operator to display MMAFighters
//pass in affVec as function parameter
//then call displayAffiliates using affVec as parameter
ostream &operator << (ostream &out, MMAFighters MMAFighters)
{
    out << "Fighter Number: " << MMAFighters.getFighterNumber() << endl;
    out << "First Name:     " << MMAFighters.getFirstName() << endl;
    out << "Last Name:      " << MMAFighters.getLastName() << endl;
    out << "Nickname:       " << MMAFighters.getNickName() << endl;
    out << "Height:         " << MMAFighters.getHeight() << endl;
    out << "Weight:         " << MMAFighters.getWeight() << endl;
    out << "Reach :         " << MMAFighters.getReach() << endl;
    out << "Stance:         " << MMAFighters.getStance() << endl;
    out << "Wins:           " << MMAFighters.getWins() << endl;
    out << "Losses:         " << MMAFighters.getLosses() << endl;
    out << "Draws:          " << MMAFighters.getDraws() << endl;
    out << "Total fights:   " << MMAFighters.getTotalFights() << endl;
    out << endl;
    
    
    return out;
}



