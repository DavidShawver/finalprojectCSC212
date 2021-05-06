/*

 */


#ifndef MMAFighters_h
#define MMAFighters_h

#include <iostream>
#include <vector>

using namespace std;

class MMAFighters
{
private:
    //Member variables
    string fighterNumber;     
    string firstName;
    string lastName;
    string nickName;
    string record;
    string wins;
    string losses;
    string draws;
    string height;
    string weight;
    string reach;
    string stance;
    string totalFights;
    bool treatAsInt;

   
public:
    //Mutator functions
    MMAFighters();     //Default Constructor
    void setFighterNumber(string _fighterNumber);
    void setFirstName(string _firstName);
    void setLastName(string _lastName);
    void setNickName(string _nickName);
    void setRecord(string _record);
    void setWins(string _wins);
    void setLosses(string _losses);
    void setDraws(string _draws);
    void setHeight(string _height);
    void setWeight(string _weight);
    void setReach(string _reach);
    void setStance(string _stance);
    void setTotalFights(string _totalFights);
    void setTreatAsInt(bool treatAsInt){ this->treatAsInt = treatAsInt;}

    
    //Accessor functions
    string getFighterNumber();
    string getFirstName();
    string getLastName();
    string getNickName();
    string getRecord();
    string getWins();
    string getLosses();
    string getDraws();
    string getWeight();
    string getHeight();
    string getReach();
    string getStance();
    string getTotalFights();
    

    
       //Overloaded << operator to display the database
    friend ostream &operator << (ostream &out, MMAFighters mmaFighters);
       
};


#endif /* MMAFighters_h */
