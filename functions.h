/*
 
 */

#ifndef functions_h
#define functions_h

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include "MMAFighters.h"
#include "BSTree.h"
#include "Menu.h"

using namespace std;


void readFromFile(BSTree*&, string);                                        //reads the data from the fightmetric.csv file
void displayRecords(BSTree*&); 
void readFightMetricFile(string file, BSTree*& tree);    
void readSavedFile(string file, BSTree*& tree);                                       //displays all of the entries
Node* search(BSTree *tree);                                                 //retrieves search results
BSTree* exact_Search(Node* node, int option, string data, BSTree* tree);    //performs exact search
BSTree* contains_Search(Node*, string, BSTree*&);                            //perform contains search
BSTree* modify_Record(BSTree*&);                                             //edit Fighter record(s)
BSTree* sort_Records(BSTree*&, int);                                         //sort records
BSTree* delete_Record(BSTree*&);                                             //delete Fighter record(s)
void save(Node* node, BSTree* &tree, string);                               //save to existing file or new file
void saveAs(ostream& out, Node* node);                                      //writes records to file
vector<MMAFighters> BSTreeVector(Node*, vector<MMAFighters>&);                    //transfer bstree to vector
BSTree* sortedTree(int, vector<MMAFighters>&);                                 //transfer vector to bstree
string make_substring(string MMAData);
std::string trim(const std::string& line);


//****************************************************************************************************
//                                      READ FROM FILE
//
//                          DESC:       Starts program by reading in file typed
//                                      in by the user.
//                          RETURNS:    Current database with new records
//****************************************************************************************************
void readFromFile(BSTree* &tree)
{
    int readType;
    cout<< "Would you like to read a \'fightmetric\' CSV file or a file saved from this database?" << endl << endl;
    cout<< "1.  FightMetric CSV File" << endl;
    cout<< "2.  Saved File" << endl;
    cout <<"3.  Exit\n" << endl;
    cin >> readType;
    
    string file;
    std::cout << endl;
    std::cout << "Enter FileName: ";
    cin >> file;
    cout << endl;

    if (readType == 1){
        readFightMetricFile(file, tree);
    }
    if (readType == 2){
        readSavedFile(file, tree);
    }
    if (readType == 3){
        return;
    }
    if (readType < 1 || readType > 3){
        "Please enter a valid choice";
    }
    //display status to user
    std::cout << "File read successfully!" << endl << endl;
    
    //ask user if they would like the tree to be displayed to console
    char choice;
    std::cout << "Display updated tree? (Y/N): \n";
    std::cin >> choice;
    std::cout << endl << endl;
    
    //char input validator
    while (!isalpha(choice))
    {
        std::cout << "Invalid selection! Please try again" << endl;
        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(256, '\n');
    }
    
    if (choice == 'y' || choice == 'Y')
    {
        //display sorted records
        displayRecords(tree);
    }
    
    
}


void readFightMetricFile(string file, BSTree* &tree){

    //holds fields of the MMA data
    string MMAData;
    char choice;
    
    //open file
    ifstream inFile;
    inFile.open(file);
    
    //close program if file not of correct type
    if (inFile.fail())
    {
        std::cout << "Error. Could not open the file" << endl;
        exit(1);
    }
    else
    {

    MMAFighters mma;
    string csvLine;

while(std::getline(inFile, csvLine))
    {      
            istringstream csvStream(csvLine);
            string csvElement;
            // read every element from the line that is seperated by commas
            // and put it into the vector or strings
            int i = 0; 
        while(std::getline(csvStream, csvElement, ','))
            { 
            if (i == 0){
                mma.setFighterNumber(csvElement);
            }
             if (i == 1){
                 mma.setFirstName(csvElement);
             }
             if (i == 2){
                 mma.setLastName(csvElement);
             }
             if (i == 3){
                 mma.setNickName(csvElement);
             }
             if (i == 4){
                 mma.setHeight(csvElement);
             }
             if (i == 5){
                 mma.setWeight(csvElement);
             }
             if (i == 6){
                mma.setReach(csvElement);
             }
             if (i == 7){
                mma.setStance(csvElement);
             }
             if (i == 8){
                mma.setWins(csvElement);
             }
              if (i == 9){
                mma.setLosses(csvElement);
             }
             if (i == 10){
                mma.setDraws(csvElement);
             }
            if (i == 11){
                mma.setTotalFights(csvElement);
             }
              i++; 
            }
        tree->addNode(mma.getFighterNumber(), mma);
        }
    }
        inFile.close();
}


void readSavedFile(string file, BSTree*& tree)
{
    //holds fields of the mma database
    string MMAData;
    char choice;
    
    //open file
    ifstream inFile;
    inFile.open(file);
    
    //close program if file not of correct type
    if (inFile.fail())
    {
        cout << "Error. Could not open the file" << endl;
        exit(1);
    }
    else
    {
        cout << "Reading in file..." << endl << endl;
        //go to until end of the file
        while (getline(inFile, MMAData))
        {
            //instantiate mmas object mma;
            MMAFighters mma;

            string data2 = make_substring(MMAData);
            //Read in records fields until the end of the file
            mma.setFighterNumber(data2);
            
            
            getline(inFile, MMAData);
            data2 = make_substring(MMAData);
            mma.setFirstName(data2);
            //inFile.ignore();
            
            getline(inFile, MMAData);
            data2 = make_substring(MMAData);
            mma.setLastName(data2);
            //inFile.ignore();

            getline(inFile, MMAData);
            data2 = make_substring(MMAData);
            mma.setNickName(data2);
            //inFile.ignore();
            
            getline(inFile, MMAData);
            data2 = make_substring(MMAData);
            mma.setHeight(data2);
            //inFile.ignore();
            
            getline(inFile, MMAData);
            data2 = make_substring(MMAData);
            mma.setWeight(data2);
            //inFile.ignore();
            
            getline(inFile, MMAData);
            data2 = make_substring(MMAData);
            mma.setReach(data2);
            //inFile.ignore();
            
            getline(inFile, MMAData);
            data2 = make_substring(MMAData);
            mma.setStance(data2);
            //inFile.ignore();
            
            getline(inFile, MMAData);
            data2 = make_substring(MMAData);
            mma.setWins(data2);
            //inFile.ignore();
            
            getline(inFile, MMAData);
            data2 = make_substring(MMAData);
            mma.setLosses(data2);
            //inFile.ignore();
            
            getline(inFile, MMAData);
            data2 = make_substring(MMAData);
            mma.setDraws(data2);
            //inFile.ignore();
            
            getline(inFile, MMAData);
            data2 = make_substring(MMAData);
            mma.setTotalFights(data2);
            //inFile.ignore();

            getline(inFile, MMAData);
            //inFile.ignore();
            //add database to BSTree
            tree->addNode(mma.getFighterNumber(), mma);
        }
        
    }
        inFile.close();
}

//****************************************************************************************************
//                                          DISPLAY RECORDS
//
//                          DESC:       Displays records, whether read in or added
//                          RETURNS:    Current database
//****************************************************************************************************

string make_substring(string MMAData){
            std::size_t found = MMAData.find(':');
            std::size_t substr_lngth = MMAData.size() - found + 1;
            string data2 = MMAData.substr(found + 1, substr_lngth);
            data2 = trim(data2);
            return data2;
}

std::string trim(const std::string& line)
{
    const char* WhiteSpace = " \t\v\r\n";
    std::size_t start = line.find_first_not_of(WhiteSpace);
    std::size_t end = line.find_last_not_of(WhiteSpace);
    return start > end ? std::string() : line.substr(start, end - start + 1);
}


void displayRecords(BSTree* &tree)
{
    //check if database is empty
    if (tree->Root() == nullptr)
        cout << "No records to display!" << endl << endl;
    else
        //display records in order by Unique ID
        tree->printInorder(tree->Root());
  
}




//****************************************************************************************************
//                                          INSERT Fighter Record
//
//                          DESC:       Allows user to add fighter records to database
//                                      User determines all fields of the new fighter
//                          RETURNS:    Updated tree with new fighter inserted
//****************************************************************************************************

void addRecord(BSTree* tree)
{
    MMAFighters _MMAFighter;  //object _MMAFighter of type MMAFighters
    string uniqueID, fName, lName, nickName; 
    string  height, _reach, _weight, _stance;
    string _wins, _losses, _draws, _totalFights; //holds mma database fields
    
    char choice = '\0';
    
    cout << "We will proceed to insert a new fighter record into the database!" << endl << endl;
    
    do
    {
        //prompts user to enter all new fields to be
        //added to database
        cout << "Enter a unique, 9-digit ID: " << endl;
        cin >> uniqueID;
        //input validator
        while (uniqueID.size() > 9 || uniqueID.size() < 9)
        {
                cout << "Please input a valid ID" << endl;
                cin >> uniqueID;
        }
        _MMAFighter.setFighterNumber(uniqueID);
        
        //first name
        cin.ignore();
        cout << "Enter a first name: ";
        getline(cin, fName);
        while (fName.size() > 20)
        {
            cout << "Please input a valid first name" << endl;
            cin >> fName;
        }
        //set first name to fName
        _MMAFighter.setFirstName(fName);
          
    
        //last name
        cout << "Enter a last name: ";
        cin >> lName;
        while (lName.size() > 20)
        {
            cout << "Please input a valid last  name" << endl;
            cin >> lName;
        }
        //set last name to lName
        _MMAFighter.setLastName(lName);
        
        //nickname
        cin.ignore();
        cout << "Enter the fighter's nickname: ";
        getline(cin, nickName);
        while (nickName.size() > 50)
        {
            cout << "Please input a valid nickName" << endl;
            cin >> nickName;
        }
        //set nickname
        _MMAFighter.setNickName(nickName);
        
        //height
        cout << "Enter the fighter's height in centimeters" << endl;
        getline(cin, height);
        while (height.size() > 15)
        {
            cout << "Please input a valid height" << endl;
            cin >> height;
        }
        //set fighter's height
        _MMAFighter.setHeight(height);
        
        //reach
        cout << "Enter the fighter's reach in inches"  << endl;
        getline(cin, _reach);
        while (_reach.size() > 20)
        {
            cout << "Please input a valid reach length" << endl;
            cin >> _reach;
        }
        //set reach
        _MMAFighter.setReach(_reach);
        
        //weight
        cout << "Enter the Fighter's weight: " << endl;
        cin >> _weight;
        while (_weight.size() > 30)
        {
            cout << "Please input a valid fighter weight" << endl;
            cin >> _weight;
        }
        _MMAFighter.setWeight(_weight);
        
        //stance
        cin.ignore();
        cout << "Enter the fighter's stance" << endl;
        getline(cin, _stance);
        while (_stance.size() > 15)
        {
            cout << "Please input a valid _stance" << endl;
            cin >> _stance;
        }
        //set stance
        _MMAFighter.setStance(_stance);
        
        //wins
        cout << "Enter the number of wins the fighter has ";
        getline(cin, _wins);
        while (_wins.size() > 50)
        {
            cout << "Please input a valid number of wins" << endl;
            cin >> _wins;
        }
        //set number of wins
        _MMAFighter.setWins(_wins);
        
        //losses
        cout << "Enter the number of losses the fighter has";
        getline(cin, _losses);
        while (_losses.size() > 50)
        {
            cout << "Please input a valid number of losses" << endl;
            cin >> _losses;
        }
        //set number of losses
        _MMAFighter.setLosses(_losses);
        
        //Draws
        cout << "Enter the number of draws the fighter has had";
        cin >> _draws;
        while (_draws.size() > 3)
        {
            cout << "Please input a valid number of draws" << endl;
            cin >> _draws;
        }
        //set number of draws
        _MMAFighter.setDraws(_draws);
        
        //Total fights
        cout << "Enter the number of total fights the fighter has had";
        cin >> _totalFights;
        while (_totalFights.size() > 11)
        {
            cout << "Please input a valid zip code" << endl;
            cin >> _totalFights;
        }
        //set number of total fights the fighter had
        _MMAFighter.setTotalFights(_totalFights);
        
                    //add mma fighter to database
        tree->addNode(_MMAFighter.getFighterNumber(), _MMAFighter);
                
        cout << "Display updated tree? (Y/N): ";
        cin >> choice;
        
        //char input validator
        while (!isalpha(choice))
        {
            cout << "Invalid selection! Please try again" << endl;
            cin >> choice;
            cin.clear();
            cin.ignore(256, '\n');
        }
        
        if (choice == 'y' || choice == 'Y')
        {
            //display sorted records
            displayRecords(tree);
        }
        
        //display message asking user if they would like to add another mma fighter
        cout << "Add another fighter to the database? (Y/N): ";
        cin >> choice;
        
        //char input validator
        while (!isalpha(choice))
        {
            cout << "Invalid selection! Please try again" << endl;
            cin >> choice;
            cin.clear();
            cin.ignore(256, '\n');
        }
        
        
    } while (choice != 'n' && choice != 'N');
    
}




//****************************************************************************************************
//                                          SEARCH RECORDS
//
//                          DESC:       Allows user to search records by multiple modes,
//                                      (exact & contains) and by multiple fields
//                          RETURNS:    Current tree
//****************************************************************************************************
Node* search(BSTree *tree)
{
    //holds user selections
    int option;
    char choice;
    
    //create new Node object node
    Node *node = new Node;
    
    //check if tree is empty
    //if empty, display appropriate message to user
    if (tree->Root() == nullptr)
        std::cout << "Invalid operation! Database is empty" << endl << endl;
    else
    {
        do
        {
            //Search type menu
            std::cout << "Select a search option" << endl;
            std::cout << "1. Exact Search" << endl;
            std::cout << "2. Contains Search" << endl;
            std::cout << "3. Exit" << endl << endl;
            std::cout << "Selection: ";
            std::cin >> option;
            
            //int input validator
            while (option < 1 || option > 3 || isdigit(option))
            {
                std::cout << "Invalid selection! Please try again" << endl;
                std::cin >> option;
                std::cin.clear();
                std::cin.ignore(256, '\n');
            }
            
            //***Exact Search***
            if (option == 1)
            {
                do
                {
                    //create new temporary BSTree object tempTree
                    BSTree *tempTree = new BSTree;
                    
                    //Field search menu
                    cout << "\tPlease select a field to search for:" << endl;
                    cout << "1. Fighter Number" << endl;
                    cout << "2. First name" << endl;
                    cout << "3. Last name" << endl;
                    cout << "4. Nickname" << endl;
                    cout << "5. Height" << endl;
                    cout << "6. Weight" << endl;
                    cout << "7. Reach" << endl;
                    cin >> option;
                    //int input validator
                    while (option < 1 || option > 7 || isdigit(option))
                    {
                        cout << "Invalid selection! Please try again" << endl;
                        cin >> option;
                        cin.clear();
                        cin.ignore(256, '\n');
                    }
                    
                    //search for fighter number
                    if (option == 1)
                    {
                        string _fighterNumber;  //holds user input for id
                        //user inputs user id to search for
                        cout << "Search for fighter Number: ";
                        cin >> _fighterNumber;
                        cout << endl << endl;

                        //search for user id using findNode() function
                        //node will hold the fighter record or nullptr
                        tempTree = exact_Search(tree->Root(), option, _fighterNumber, tempTree);
                        
                        //display fighter record and appropriate message if found
                        if (tempTree->Root() != nullptr)
                        {
                            cout << "Fighter record found!\n\n" << endl;
                            tempTree->printInorder(tempTree->Root());
                            cout << endl;
                        }
                        //record not found
                        else
                            cout << "Righter record not found" << endl << endl;
                    }
                    
                    //search for first name
                    else if (option == 2)
                    {
                        string _first_Name;   //holds user input first name
                        cout << "Search first name: ";
                        cin >> _first_Name;
                        cout << endl << endl;
        
                        //call exact_Search() function
                        //assign temporary tree tempTree to exact_Search()
                        //tempTree will hold results
                        tempTree = exact_Search(tree->Root(), option, _first_Name, tempTree);
                    
                        //if tree is not empty, display results
                        if (tempTree->Root() != nullptr)
                        {
                            cout << "Fighter record(s) found!" << endl;
                            tempTree->printInorder(tempTree->Root());
                            cout << endl;
                        }
                        //record not found
                        else
                            cout << "Fighter record(s) not found" << endl << endl;
                    }

                    //Last name
                    else if (option == 3)
                    {
                        cin.ignore();
                        string _last_Name;
                        cout << "Search last name: ";
                        getline(cin, _last_Name);
                        cout << endl << endl;
                        
                        //call exact_Search() function
                        //assign temporary tree tempTree to exact_Search()
                        //tempTree will hold results
                        tempTree = exact_Search(tree->Root(), option, _last_Name, tempTree);
                        
                        //if tree is not empty, display results
                        if (tempTree->Root() != nullptr)
                        {
                            cout << "Fighter record(s) found!" << endl;
                            tempTree->printInorder(tempTree->Root());
                            cout << endl;
                        }
                        //record not found
                        else
                            cout << "Fighter record(s) not found" << endl << endl;
                    }
                    
                    //nickname
                    else if (option == 4)
                    {
                        cin.ignore();
                        string _nick_Name;
                        cout << "Search for nick name of the fighter record you want to delete: ";
                        getline(cin, _nick_Name);
                        cout << endl << endl;
                        
                        //call exact_Search() function
                        //assign temporary tree tempTree to exact_Search()
                        //tempTree will hold results
                        tempTree = exact_Search(tree->Root(), option, _nick_Name, tempTree);
                        
                        //if tree is not empty, display results
                        if (tempTree->Root() != nullptr)
                        {
                            cout << "Fighter record(s) found!" << endl << endl;
                            tempTree->printInorder(tempTree->Root());
                            cout << endl;
                        }
                        //record not found
                        else
                            cout << "Fighter record(s) not found" << endl << endl;
                    }
                    
                    //height
                    else if (option == 5)
                    {
                        cin.ignore();
                        string _height;
                        cout << "Search for height ";
                        getline(cin, _height);
                        cout << endl << endl;
                        
                        //call exact_Search() function
                        //assign temporary tree tempTree to exact_Search()
                        //tempTree will hold results
                        tempTree = exact_Search(tree->Root(), option, _height, tempTree);
                        
                        //if tree is not empty, display results
                        if (tempTree->Root() != nullptr)
                        {
                            cout << "Fighter record(s) found!" << endl;
                            tempTree->printInorder(tempTree->Root());
                            cout << endl;
                        }
                        //record not found
                        else
                            cout << "Fighter record(s) not found" << endl << endl;
                    }
                    
                    //weight
                    else if (option == 6)
                    {
                        cin.ignore();
                        string _weight;
                        cout << "Search by weight: ";
                        getline(cin, _weight);
                        cout << endl << endl;
                        
                        //call exact_Search() function
                        //assign temporary tree tempTree to exact_Search()
                        //tempTree will hold results
                        tempTree = exact_Search(tree->Root(), option, _weight, tempTree);
                        
                        //if tree is not empty, display results
                        if (tempTree->Root() != nullptr)
                        {
                            cout << "(s) found!" << endl;
                            tempTree->printInorder(tempTree->Root());
                            cout << endl;
                        }
                        //record not found
                        else
                            cout << "Fighter  record(s) not found" << endl << endl;
                    }
                    
                    //reach
                    else if (option == 7)
                    {
                        string _reach;
                        cout << "Search by fighter's reach: ";
                        cin >> _reach;
                        cout << endl << endl;
                        
                        //call exact_Search() function
                        //assign temporary tree tempTree to exact_Search()
                        //tempTree will hold results
                        tempTree = exact_Search(tree->Root(), option, _reach, tempTree);
                        
                        //if tree is not empty, display results
                        if (tempTree->Root() != nullptr)
                        {
                            cout << "Fighter record(s) found!" << endl;
                            tempTree->printInorder(tempTree->Root());
                            cout << endl;
                        }
                        //record not found
                        else
                            cout << "Fighter record(s) not found" << endl << endl;
                    }
                    
                    //Allow user to perform another search using a different field
                    cout << "Do you want to search again? (Y/N)\n" << endl;
                    cin >> choice;
                    //char input validator

                    while (!isalpha(choice))
                    {
                        cout << "Invalid selection! Please try again" << endl;
                        cin >> choice;
                        cin.clear();
                        cin.ignore(256, '\n');
                    }
                    
                    if (choice == 'n' || choice == 'N')
                    {
                        node = tempTree->Root();
                    }
                    
                } while (choice != 'n' && choice != 'N');
            }
            //Contains Search
            else if (option == 2)
            {
                do
                {
                    //create new BSTree object temp
                    BSTree *temp = new BSTree;
                    //holds user contains search data
                    string containsData;
        
                    std::cin.ignore();
                    //asks user to type in what they're searching for
                    std::cout << "Search: ";
                    getline(std::cin, containsData);
                    std::cout << endl;
                    
                    //passing temp to the temporary binary search tree
                    //returned from contains_Search
                    temp = contains_Search(tree->Root(), containsData, temp);
                    
                    //if the tree is not empty, display the search results
                    //else, display appropriate message to user
                    if (temp->Root() != nullptr)
                    {
                        
                        std::cout << "Fighter record(s) found!" << endl;
                        temp->printInorder(temp->Root());
                        std::cout << endl;
                    }
                    else
                        std::cout << "Fighter record(s) not found" << endl << endl;
                    
                    //ask user if they would like to perform another
                    //contains search
                    std::cout << "Perform another 'contains' search? (Y/N)" << endl;
                    std::cin >> choice;
                    //char input validator
                    while (!isalpha(choice))
                    {
                        std::cout << "Invalid selection! Please try again" << endl;
                        std::cin >> choice;
                        std::cin.clear();
                        std::cin.ignore(256, '\n');
                    }
                    if (choice == 'n' || choice == 'N')
                    {
                        node = temp->Root();
                    }
                    
                } while (choice != 'n' && choice != 'N');
            }
            
        } while (option != 3 );
     
        //returns Fighter record(s) user searched for or nullptr if not record found
        return node;
    }
    //returns Fighter record(s) user searched for or nullptr if not record found
    return node;
}





//****************************************************************************************************
//                                      EXACT SEARCH
//
//****************************************************************************************************
BSTree* exact_Search(Node* node, int option, string data, BSTree* tree)
{
    if (node != nullptr)
    {
        //user id
        if (option == 1)
        {
            //if user input search is equal to id in database,
            //add the node to the temporary tree
            if (node->getMMAFighter().getFighterNumber() == data)
                tree->addNode(node->Key(), node->getMMAFighter());
        }
        //first name
        if (option == 2)
        {
            //if user input search is equal to first name in database,
            //add the node to the temporary tree
            if (node->getMMAFighter().getFirstName() == data)
                tree->addNode(node->Key(), node->getMMAFighter());
        }
        //last name
        else if (option == 3)
        {
            //if user input search is equal to last name in database,
            //add the node to the temporary tree
            if (node->getMMAFighter().getLastName() == data)
                tree->addNode(node->Key(), node->getMMAFighter());
        }
        //nickname
        else if (option == 4)
        {
            //if user input search is equal to company in database,
            //add the node to the temporary tree
            if (node->getMMAFighter().getNickName() == data)
                tree->addNode(node->Key(), node->getMMAFighter());
        }
        //height
        else if (option == 5)
        {
            //if user input search is equal to the height,
            //add the node to the temporary tree
            if (node->getMMAFighter().getHeight() == data)
                tree->addNode(node->Key(), node->getMMAFighter());
        }
        //weight
        else if (option == 7)
        {
            //if user input search is equal to the weight, 
            //add the node to the temporary tree
            if (node->getMMAFighter().getWeight() == data)
                tree->addNode(node->Key(), node->getMMAFighter());
        }
        //reach
        else if (option == 8)
        {
            //if user input search is equal to the reach,
            //add the node to the temporary tree
            if (node->getMMAFighter().getReach() == data)
                tree->addNode(node->Key(), node->getMMAFighter());
        }
      
        //Traverse entire tree
        exact_Search(node->Left(), option, data, tree);
        exact_Search(node->Right(), option, data, tree);
    }
    
    return tree;
}



//****************************************************************************************************
//                                      CONTAINS SEARCH
//
//****************************************************************************************************
BSTree* contains_Search(Node* node, string data, BSTree* &tree)
{
    string search;
    size_t found = 0;
    
    if (node != nullptr)
    {
        //User id
    
        //assign search to first record in database
        search = node->getMMAFighter().getFighterNumber();
        //assign found to results of search.find() function
        found = search.find(data);
        //if found doesn't reach end of the string, add to tree
        if (found != string::npos)
            tree->addNode(node->Key(), node->getMMAFighter());
    
        //First name
        //assign search to first record in database
        search = node->getMMAFighter().getFirstName();
        found = search.find(data);
        if (found != string::npos)
            tree->addNode(node->Key(), node->getMMAFighter());
    
         //Last name
        //assign search to first record in database
        search = node->getMMAFighter().getLastName();
        found = search.find(data);
        if (found != string::npos)
            tree->addNode(node->Key(), node->getMMAFighter());
    
        //nickname
        //assign search to first record in database
        search = node->getMMAFighter().getNickName();
        found = search.find(data);
        if (found != string::npos)
            tree->addNode(node->Key(), node->getMMAFighter());
    
        //Height
        //assign search to first record in database
        search = node->getMMAFighter().getHeight();
        found = search.find(data);
        if (found != string::npos)
            tree->addNode(node->Key(), node->getMMAFighter());
    
        //Weight
        //assign search to first record in database
        search = node->getMMAFighter().getWeight();
        found = search.find(data);
        if (found != string::npos)
            tree->addNode(node->Key(), node->getMMAFighter());
        
        //Reach
        //assign search to first record in database
        search = node->getMMAFighter().getReach();
        found = search.find(data);
        if (found != string::npos)
            tree->addNode(node->Key(), node->getMMAFighter());
        
        //recursively traverse entire tree
        contains_Search(node->Left(), data, tree);
        contains_Search(node->Right(), data, tree);
        
    }
    
    return tree;
}





//****************************************************************************************************
//                                      MODIFY RECORDS
//
//                            DESC:       User searches (exact or contain) for record
//                                        they would like to edit. If user saves changes,
//                                        updated record is added to database.
//                            RETURNS:    Updated tree with modified records.
//****************************************************************************************************
BSTree* modify_Record(BSTree* &tree)
{
    //ask user to search for record to edit
    //call search records function
    string searchData;
    char selection;
    int option;
    Node *tempNode = new Node();
    MMAFighters MMA;
    
    //check if database is empty
    if (tree->Root() == nullptr)
        cout << "Invalid operation! Database is empty" << endl;
    else
    {
        do
        {
            //holds user inputs
            string newData;
            cout << "Search for a record to modify? (Y/N)" << endl;
            cin >> selection;
            
            //char input validator
            while (!isalpha(selection))
            {
                cout << "Invalid selection! Please try again" << endl;
                cin >> selection;
                cin.clear();
                cin.ignore(256, '\n');
            }
            
            if (selection == 'y' || selection == 'Y')
            {
                //assign tempNode to record returned from search() function
                tempNode = search(tree);
            }
            
            //display search result and ask if user would like to delete record
            
            tree->printInorder(tempNode);
            
            cout << "Would you like to modify this record? (Y/N)" << endl;
            cin >> selection;
            searchData = tempNode->Key();       //assign searchData to tempNode key
            
            //char input validator
            while (!isalpha(selection))
            {
                cout << "Invalid selection! Please try again" << endl;
                cin >> selection;
                cin.clear();
                cin.ignore(256, '\n');
            }
            
            //user chooses to modify record
            if (selection == 'y' || selection == 'Y')
            {
                do
                {
                    cout << "\tSelect field to edit: " << endl << endl;
                    cout << "1. Fighter Number" << endl;
                    cout << "2. First name" << endl;
                    cout << "3. Last name" << endl;
                    cout << "4. Nickname" << endl;
                    cout << "5. Height" << endl;
                    cout << "6. Weight" << endl;
                    cout << "7. Reach" << endl;
                    cout << "8. Stance" << endl;
                    cout << "9. Wins" << endl;
                    cout << "10. Losses" << endl;
                    cout << "11. Draws" << endl;
                    cout << "12. Total Fights" << endl;
                    cout << "Selection: ";
                    cin >> option;   //user selection
                    //int input validator
                    while (option < 1 || option > 12 || isdigit(option))
                    {
                        cout << "Invalid selection! Please try again" << endl;
                        cin >> option;
                        cin.clear();
                        cin.ignore(256, '\n');
                    }
                    
                    //edit id
                    if (option == 1)
                    {
                        cout << "Enter the new Fighter Number: ";
                        cin >> newData;
                        tempNode->getMMAFighter().setFighterNumber(newData);
                        tempNode->setKey(newData);
                    }
                    //edit first name
                    else if (option == 2)
                    {
                        cout << "Enter the new user first name: ";
                        cin >> newData;
                        tempNode->getMMAFighter().setFirstName(newData);
                    }
                    //edit last name
                    else if (option == 3)
                    {
                        cout << "Enter the new user last name: ";
                        cin >> newData;
                        tempNode->getMMAFighter().setLastName(newData);
                    }

                    //nickname
                    else if (option == 4)
                    {
                        cin.ignore();
                        cout << "Enter the new nickname: ";
                        getline(cin, newData);
                        tempNode->getMMAFighter().setNickName(newData);
                    }
                    //height
                    else if (option == 5)
                    {
                        cout << "Enter the new height: ";
                        cin >> newData;
                        tempNode->getMMAFighter().setHeight(newData);
                    }
                    //weight
                    else if (option == 6)
                    {
                        cout << "Enter the new weight: ";
                        cin >> newData;
                        //set new weight to newData
                        tempNode->getMMAFighter().setWeight(newData);
                    }
                    //reach
                    else if (option == 7)
                    {
                        cout << "Enter the new reach length: ";
                        cin >> newData;
                        //set new length to newData
                        tempNode->getMMAFighter().setReach(newData);
                    }
                    //stance
                    else if (option == 8)
                    {
                        cout << "Enter the new stance: ";
                        cin >> newData;
                        //set new stance to newData
                        tempNode->getMMAFighter().setStance(newData);
                    }
                    //wins
                    else if (option == 9)
                    {
                        cin.ignore();
                        cout << "Enter the new number of wins: ";
                        getline(cin, newData);
                        //set new wins value to newData
                        tempNode->getMMAFighter().setWins(newData);
                    }
                    // losses
                    else if (option == 10)
                    {
                        cin.ignore();
                        cout << "Enter the new number of losses: ";
                        getline(cin, newData);
                        //set new losses value to newData
                        tempNode->getMMAFighter().setLosses(newData);
                    }
                    //draws
                    else if (option == 11)
                    {
                        cout << "Enter the new number of draws: ";
                        cin >> newData;
                        //sett new number of draws to newData
                        tempNode->getMMAFighter().setDraws(newData);
                    }
                    //total fights
                    else if (option == 12)
                    {
                        cout << "Enter the new number of total fights: ";
                        cin >> newData;
                        //set new total number of fights to newData;
                        tempNode->getMMAFighter().setTotalFights(newData);
                    }
                    
                    cout << endl;
                    // display edited mma info
                    tree->printInorder(tempNode);
                    cout << "Would you like to save your changes? (Y/N)" << endl;
                    cin >> selection;
                    //char input validator
                    while (!isalpha(selection))
                    {
                        cout << "Invalid selection! Please try again" << endl;
                        cin >> selection;
                        cin.clear();
                        cin.ignore(256, '\n');
                    }
                    
                    //user selects to save changes made
                    if (selection == 'y' || selection == 'Y')
                    {
                        //delete record from database
                        tree->deleteNode(searchData);
                        //add updated record to database
                        tree->addNode(tempNode->Key(), tempNode->getMMAFighter());
                    }
                    
                    //ask user if they would like to modify a different field
                    cout << "Would you like to modify another field? (Y/N)" << endl;
                    cin >> selection;
                    //char input validator
                    while (!isalpha(selection))
                    {
                        cout << "Invalid selection! Please try again" << endl;
                        cin >> selection;
                        cin.clear();
                        cin.ignore(256, '\n');
                    }
                    
                } while (selection != 'n' && selection != 'N');
                    
            }
            
            cout << "Display updated tree? (Y/N)" << endl;
            cin >> selection;
            cout << endl << endl;
            
            //char input validator
            while (!isalpha(selection))
            {
                cout << "Invalid selection! Please try again" << endl;
                cin >> selection;
                cin.clear();
                cin.ignore(256, '\n');
            }
            
            if (selection == 'y' || selection == 'Y')
            {
                //display sorted records
                displayRecords(tree);
            }
            
            //ask user if they would liek to modify a different record
            cout << "Modify another record? (Y/N)" << endl;
            cin >> selection;
            
            //char input validator
            while (!isalpha(selection))
            {
                cout << "Invalid selection! Please try again" << endl;
                cin >> selection;
                cin.clear();
                cin.ignore(256, '\n');
            }
            
        } while (selection != 'n' && selection != 'N');
            
    }
    
    return tree;
}









//****************************************************************************************************
//                                           SORT RECORDS
//                        DESC:     Sorts the database by user choice of field
//                        RETURNS:  Updated database
//****************************************************************************************************
BSTree* sort_Records(BSTree* &tree)
{
    vector<MMAFighters> MMAVector;           //holds vector of MMAFighters mma
    BSTree *tempTree = new BSTree();    //create new BSTree object tempTree
    char choice;                        //holds user menu choice
    int option;
    
    //check if tree is empty
    if (tree->Root() == nullptr)
        cout << "Invalid operation! Database is empty" << endl << endl;
    else
    {
        do
        {
            //Sort menu
            cout << "\tHow would you like to sort the records?" << endl;
            cout << "1. Fighter number" << endl;
            cout << "2. First name" << endl;
            cout << "3. Last name" << endl;
            cout << "4. Nickname" << endl;
            cout << "5. Height" << endl;
            cout << "6. Weight" << endl;
            cout << "7. Reach" << endl;
            cout << "8. Stance" << endl;
            cout << "9. Number of wins" << endl;
            cout << "10. Number of losses" << endl;
            cout << "11. Number of draws" << endl;
            cout << "12. Number of total fights" << endl;
            cout << "Selection: ";
            cin >> option;   //user selection
            
            //int input validator
            while (option < 1 || option > 12 || isdigit(option))
            {
                cout << "Invalid selection! Please try again" << endl;
                cin >> option;
                cin.clear();
                cin.ignore(256, '\n');
            }
            

            //User ID
            if (option == 1)
            {
                //call function BSTReeVector to insert database into MMAVector Vector
                //assign MMAVector to BSTreeVector
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
 

                //call function sortedTree to transfer database in vector to tempTree
                tempTree = sortedTree(option, MMAVector);
                cout << "Database now sorted by user ID!" << endl << endl;
            }
            
            //First name
            else if (option == 2)
            {
                //call function BSTReeVector to insert database into MMAVector Vector
                //assign MMAVector to BSTreeVector
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                //call function sortedTree to transfer database in vector to tempTree
                tempTree = sortedTree(option, MMAVector);
                cout << "Database now sorted by first name!" << endl << endl;
            }
            
            

            //Last name
            else if (option == 3)
            {
                //call function BSTReeVector to insert database into MMAVector Vector
                //assign MMAVector to BSTreeVector
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                //call function sortedTree to transfer database in vector to tempTree
                tempTree = sortedTree(option, MMAVector);
                cout << "Database now sorted by last name!" << endl << endl;
            }
            
            //Nick name
            else if (option == 4)
            {
                //call function BSTReeVector to insert database into MMAVector Vector
                //assign MMAVector to BSTreeVector
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                //call function sortedTree to transfer database in vector to tempTree
                tempTree = sortedTree(option, MMAVector);
                cout << "Database now sorted by nickname!" << endl << endl;
            }
            
            //Height
            else if (option == 5)
            {
                //call function BSTReeVector to insert database into MMAVector Vector
                //assign MMAVector to BSTreeVector
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                //call function sortedTree to transfer database in vector to tempTree
                tempTree = sortedTree(option, MMAVector);
                cout << "Database now sorted by height!" << endl << endl;
            }
            
            //Weight
            else if (option == 6)
            {
                //call function BSTReeVector to insert database into MMAVector Vector
                //assign MMAVector to BSTreeVector
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                //call function sortedTree to transfer database in vector to tempTree
                tempTree = sortedTree(option, MMAVector);
                cout << "Database now sorted by weight!" << endl << endl;
            }
            
            //Reach
            else if (option == 7)
            {
                //call function BSTReeVector to insert database into MMAVector Vector
                //assign MMAVector to BSTreeVector
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                //call function sortedTree to transfer database in vector to tempTree
                tempTree = sortedTree(option, MMAVector);
                cout << "Database now sorted by fighter reach!" << endl << endl;
            }
            
            //Stance
            else if (option == 8)
            {
                //call function BSTReeVector to insert database into MMAVector Vector
                //assign MMAVector to BSTreeVector
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                //call function sortedTree to transfer database in vector to tempTree
                tempTree = sortedTree(option, MMAVector);
                cout << "Database now sorted by fighter stance!" << endl << endl;
            }
            
            //Wins
            else if (option == 9)
            {
                //call function BSTReeVector to insert database into MMAVector Vector
                //assign MMAVector to BSTreeVector
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                //call function sortedTree to transfer database in vector to tempTree
                tempTree = sortedTree(option, MMAVector);
                cout << "Database now sorted by number of wins!" << endl << endl;
            }
            
            //Losses
            else if (option == 10)
            {
                //call function BSTReeVector to insert database into MMAVector Vector
                //assign MMAVector to BSTreeVector
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                //call function sortedTree to transfer database in vector to tempTree
                tempTree = sortedTree(option, MMAVector);
                cout << "Database now sorted by number of losses!" << endl << endl;
            }
            
            //Draws
            else if (option == 11)
            {
                //call function BSTReeVector to insert database into MMAVector Vector
                //assign MMAVector to BSTreeVector
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                //call function sortedTree to transfer database in vector to tempTree
                tempTree = sortedTree(option, MMAVector);
                cout << "Database now sorted by number of draws!" << endl << endl;
            }
            
            //Total Fights
            else if (option == 12)
            {
                //call function BSTReeVector to insert database into MMAVector Vector
                //assign MMAVector to BSTreeVector
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                //call function sortedTree to transfer database in vector to tempTree
                tempTree = sortedTree(option, MMAVector);
                cout << "Database now sorted by total number of fights!" << endl << endl;
            }
            
            
            cout << "Display sorted records? (Y/N)" << endl;
            cin >> choice;
            
            //char input validator
            while (!isalpha(choice))
            {
                cout << "Invalid selection! Please try again" << endl;
                cin >> choice;
                cin.clear();
                cin.ignore(256, '\n');
            }
            
            if (choice == 'y' || choice == 'Y')
            {
                //display sorted records
                displayRecords(tempTree);
            }
            
            //ask user if they would like to sort by different fiel
            cout << "Sort by a different field? (Y/N)" << endl;
            cin >> choice;
            
            //char input validator
            while (!isalpha(choice))
            {
                cout << "Invalid selection! Please try again" << endl;
                cin >> choice;
                cin.clear();
                cin.ignore(256, '\n');
            }
            
        } while (choice != 'n' && choice != 'N');
        
    }
    //return updated tree
    return tempTree;
}




//****************************************************************************************************
//                                          DELETE RECORDS
//                        DESC:     Deletes records based on user search result
//                        RETURNS:  Updated tree
//****************************************************************************************************

BSTree* delete_Record(BSTree* &tree)
{
    Node *tempNode = new Node;      //create new temporary node
    char choice;                    //holds user menu choices
    
    //check if database is empty
    if (tree->Root() == nullptr)
        cout << "Invalid operation! Database is empty" << endl << endl;
    else
    {
        do
        {
            //tempNode holds the record that the user searched for
            tempNode = search(tree);
            
            //display record and ask if user would like to permanently continue to
            //delete the record
            cout << tempNode->getMMAFighter() << endl;
            cout << "Delete this record? (Y/N)" << endl;
            cin >> choice;
            //char input validator
            while (!isalpha(choice))
            {
                cout << "Invalid selection! Please try again" << endl;
                cin >> choice;
                cin.clear();
                cin.ignore(256, '\n');
            }
            
            //delete record from database by calling deleteNode()
            if (choice == 'y' || choice == 'Y')
            {
                //use key from tempNode to delete record
                cout << "Deleting MMA records..." << endl << endl;
                tree->deleteNode(tempNode->Key());
            }

            //Ask user if they would like to delete another record
            cout << "Search for a different record to delete? (Y/N)" << endl;
            cin >> choice;
            //char input validator
            while (!isalpha(choice))
            {
                cout << "Invalid selection! Please try again" << endl;
                cin >> choice;
                cin.clear();
                cin.ignore(256, '\n');
            }
            
        } while (choice != 'n' && choice != 'N');
        
    }
    
    cout << "Display updated tree? (Y/N)" << endl;
    cin >> choice;
    //char input validator
    while (!isalpha(choice))
    {
        cout << "Invalid selection! Please try again" << endl;
        cin >> choice;
        cin.clear();
        cin.ignore(256, '\n');
    }
    
    if (choice == 'y' || choice == 'Y')
    {
        displayRecords(tree);
    }
    //return updated tree with record removed from database
    return tree;
    
}




//****************************************************************************************************
//                                          Save to file
//                              DESC:
//                              RETURNS:
//****************************************************************************************************
void save(Node* node, BSTree* &tree, string fileName)
{
    int option;                     //holds user option
    vector<MMAFighters> MMAVector;    //temporary vector of MMAFighters MMAVector
    char choice;                    //hodsl user menu choice
    
    //user selects preferred save option
    cout << "\tPLEASE SELECT A SAVE OPTION" << endl;
    cout << "1. Save" << endl;
    cout << "2. Save As" << endl;
    cout << "3. Exit" << endl;
    cin >> option;
    
    //int input validator
    while (option < 1 || option > 3 || isdigit(option))
    {
        cout << "Invalid selection! Please try again" << endl;
        cin >> option;
        cin.clear();
        cin.ignore(256, '\n');
    }
    
    //Save
    if (option == 1)
    {
        ofstream outfile;
        outfile.open(fileName);
        
        do
        {
            //create new BSTree object temp
            BSTree *temp = new BSTree;
            
            cout << "\tHOW WOULD YOU LIKE TO SORT THE RECORDS?" << endl << endl;
            cout << "1. User ID" << endl;
            cout << "2. First name" << endl;
            cout << "3. Last name" << endl;
            cout << "4. Nick name" << endl;
            cout << "5. Height" << endl;
            cout << "6. Weight" << endl;
            cout << "7. Reach" << endl;
            cout << "8. Stance" << endl;
            cout << "9. Number of Wins" << endl;
            cout << "10. Number of Losses" << endl;
            cout << "11. Number of Draws" << endl;
            cout << "12. Total Number of Fights" << endl << endl;
            cout << "Selection: ";
            cin >> option;   //user selection
            //int input validator
            while (option < 1 || option > 12 || isdigit(option))
            {
                cout << "Invalid selection! Please try again" << endl;
                cin >> option;
                cin.clear();
                cin.ignore(256, '\n');
            }
            
            //User ID
            if (option == 1)
            {
                //call function BSTReeVector to insert database into mma Vector
                //assign mma to BSTreeVector
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                //call function sortedTree to transfer database in vector to tempTree
                temp = sortedTree(option, MMAVector);
                //call saveAs function to save to file
                saveAs(outfile, temp->Root());
            }
            //first name
            else if (option == 2)
            {
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                temp = sortedTree(option, MMAVector);
                saveAs(outfile, temp->Root());
            }
            //last name
            else if (option == 3)
            {
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                temp = sortedTree(option, MMAVector);
                saveAs(outfile, temp->Root());
            }
            //nick name
            else if (option == 4)
            {
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                temp = sortedTree(option, MMAVector);
                saveAs(outfile, temp->Root());
            }
            //height
            else if (option == 5)
            {
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                temp = sortedTree(option, MMAVector);
                saveAs(outfile, temp->Root());
            }
            //weight
            else if (option == 6)
            {
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                temp = sortedTree(option, MMAVector);
                saveAs(outfile, temp->Root());
            }
            //reach
            else if (option == 7)
            {
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                temp = sortedTree(option, MMAVector);
                saveAs(outfile, temp->Root());
            }
            //stance
            else if (option == 8)
            {
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                temp = sortedTree(option, MMAVector);
                saveAs(outfile, temp->Root());
            }
            //wins
            else if (option == 9)
            {
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                temp = sortedTree(option, MMAVector);
                saveAs(outfile, temp->Root());
            }
            //losses
            else if (option == 10)
            {
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                temp = sortedTree(option, MMAVector);
                saveAs(outfile, temp->Root());
            }
            //draws
            else if (option == 11)
            {
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                temp = sortedTree(option, MMAVector);
                saveAs(outfile, temp->Root());
            }
            //total number of fights
            else if (option == 12)
            {
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                temp = sortedTree(option, MMAVector);
                saveAs(outfile, temp->Root());
            }
            
            //ask user if they would like to sort by a different field
            cout << "File saved. \n\n"<< endl;
            cout << "Would you like to save another file? (Y/N)" << endl;

            
        } while (choice != 'n' && choice != 'N');
        
        //close the file
        outfile.close();
    }
    //Save As
    else if (option == 2)
    {
        string file;
    
        cout << "Enter the name of the file you're saving to:" << endl;
        cin >> file;
        
        ofstream outFile;
        outFile.open(file);
        
        do
        {
            
            //create new BSTree object tempTree
            BSTree *tempTree = new BSTree;
            
            cout << "\tHOW WOULD YOU LIKE TO SORT THE RECORDS?" << endl << endl;
            cout << "1. User ID" << endl;
            cout << "2. First name" << endl;
            cout << "3. Last name" << endl;
            cout << "4. Nick name" << endl;
            cout << "5. Height" << endl;
            cout << "6. Weight" << endl;
            cout << "7. Reach" << endl;
            cout << "8. Stance" << endl;
            cout << "9. Number of Wins" << endl;
            cout << "10. Number of Losses" << endl;
            cout << "11. Number of Draws" << endl;
            cout << "12. Total Number of Fights" << endl;
            cout << "Selection: ";
            cin >> option;   //user selection
            
            //int input validator
            while (option < 1 || option > 12 || isdigit(option))
            {
                cout << "Invalid selection! Please try again" << endl;
                cin >> option;
                cin.clear();
                cin.ignore(256, '\n');
            }
            
            //sort by fighter id
            if (option == 1)
            {
                //call function BSTReeVector to insert database into mma Vector
                //assign mma to BSTreeVector
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                
                //call function sortedTree to transfer database in vector to tempTree
                tempTree = sortedTree(option, MMAVector);
                
                //call saveAs function to write to file
                saveAs(outFile, tempTree->Root());
            }
            //sort by first name
            else if (option == 2)
            {
                
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                tempTree = sortedTree(option, MMAVector);
                saveAs(outFile, tempTree->Root());
            }
            //sort by last name
            else if (option == 3)
            {
                
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                tempTree = sortedTree(option, MMAVector);
                saveAs(outFile, tempTree->Root());
            }
            //sort by nick name
            else if (option == 4)
            {
                
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                tempTree = sortedTree(option, MMAVector);
                saveAs(outFile, tempTree->Root());
            }
            //sort by height
            else if (option == 5)
            {
                
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                tempTree = sortedTree(option, MMAVector);
                saveAs(outFile, tempTree->Root());
            }
            //sort by weight
            else if (option == 6)
            {
                
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                tempTree = sortedTree(option, MMAVector);
                saveAs(outFile, tempTree->Root());
            }
            //sort by reach
            else if (option == 7)
            {
                
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                tempTree = sortedTree(option, MMAVector);
                saveAs(outFile, tempTree->Root());
            }
            //sort by stance
            else if (option == 8)
            {
                
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                tempTree = sortedTree(option, MMAVector);
                saveAs(outFile, tempTree->Root());
            }
            //sort by number of wins
            else if (option == 9)
            {
                
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                tempTree = sortedTree(option, MMAVector);
                saveAs(outFile, tempTree->Root());
            }
            //sort by number of losses
            else if (option == 10)
            {
                
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                tempTree = sortedTree(option, MMAVector);
                saveAs(outFile, tempTree->Root());
            }
            //sort by number of draws
            else if (option == 11)
            {
                
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                tempTree = sortedTree(option, MMAVector);
                saveAs(outFile, tempTree->Root());
            }
            //sort by total number of fights
            else if (option == 12)
            {
                
                MMAVector = BSTreeVector(tree->Root(), MMAVector);
                tempTree = sortedTree(option, MMAVector);
                saveAs(outFile, tempTree->Root());
            }            
            
            
            //display status message to user
            cout << "Saving to file..." << endl << endl;
            cout << "File saved successfully!" << endl << endl;
            
            cout << "Sort file by another field? (Y/N)" << endl;
            cin >> choice;
            
            //char input validator
            while (!isalpha(choice))
            {
                cout << "Invalid selection! Please try again" << endl;
                cin >> choice;
                cin.clear();
                cin.ignore(256, '\n');
            }
            
        } while (choice != 'n' && choice != 'N');
        
        //close the file
        outFile.close();
        
    }
    

}


//***********************************************
//                  SAVE AS
//DESC: Saves the database to a new, user
//      input file
//***********************************************
void saveAs(ostream& outFile, Node* node)
{
    //if tree is not empty, recursively save MMAFighters to new file using
    //ostream object outFile
    if (node != nullptr)
    {
        //recursively search entire tree
        saveAs(outFile, node->Left());
        
        //write MMAFighters to file
        outFile << "Fighter number:     " << node->getMMAFighter().getFighterNumber() << endl;
        outFile << "First name:         " << node->getMMAFighter().getFirstName() << endl;
        outFile << "Last name:          " << node->getMMAFighter().getLastName() << endl;
        outFile << "Nick name:          " << node->getMMAFighter().getNickName() << endl;
        outFile << "Height:             " << node->getMMAFighter().getHeight() << endl;
        outFile << "Weight:             " << node->getMMAFighter().getWeight() << endl;
        outFile << "Reach:              " << node->getMMAFighter().getReach() << endl;
        outFile << "Stance:             " << node->getMMAFighter().getStance() << endl;
        outFile << "Number of wins:     " << node->getMMAFighter().getWins() << endl;
        outFile << "Number of losses:   " << node->getMMAFighter().getLosses() << endl;
        outFile << "Number of draws:    " << node->getMMAFighter().getDraws() << endl;
        outFile << "Total fights:       " << node->getMMAFighter().getTotalFights() << endl;      
        outFile << "|" << endl;

        
        //recursively traverse entire tree
        saveAs(outFile, node->Right());
    }
}



//***********************************************
//                  BSTReeVector
//DESC: Inserts records from binary search tree
//      into a temporary vector of MMAFighters.
//      Function will recursively traverse tree
//***********************************************
vector<MMAFighters> BSTreeVector(Node* node, vector<MMAFighters> &MMAVector)
{
    //check if database is empty
    if (node != nullptr)
    {
        //add MMAFighters to the vector MMAVector
        MMAVector.push_back(node->getMMAFighter());
        //recursively traverse entire tree
        BSTreeVector(node->Left(), MMAVector);
        BSTreeVector(node->Right(), MMAVector);
    }
    
    //return database vector
    return MMAVector;
}



//***********************************************
//                  sortedTree
//DESC: Inserts records from temporary vector of
//      MMAFighters into a new, temporary binary
//      search tree. Records are inserted in sorted order of
//      user's choice of field by setting said field
//      as the new key.
//***********************************************
BSTree* sortedTree(int option, vector<MMAFighters> &c)
{
    BSTree *tempTree;  //create new BSTree object tempTree
    MMAFighters temp;                  //Create new MMAFighters object temp
    
    if(option == 1 || (option >= 5 && option <= 7) ||
        (option >= 9 && option <= 12) ) {
            
        tempTree = new BSTree(true);
    } else {
        tempTree = new BSTree;
    }

    if (option == 1)
    {
        //sort the vector
        cout << "Sorting the database..." << endl << endl;
        
        //add vector to database
        for (int i = 0; i < c.size(); i++)
        {
            tempTree->addNode(c[i].getFighterNumber(), c[i]);
        }
    }
    else if (option == 2)
    {
        //sort the vector
        cout << "Sorting the database..." << endl << endl;

        //add vector to database
        for (int i = 0; i < c.size(); i++)
        {
            tempTree->addNode(c[i].getFirstName(), c[i]);
        }
    }
    else if (option == 3)
    {
        //sort the vector
        cout << "Sorting the database..." << endl << endl;
        
        //add vector to database
        for (int i = 0; i < c.size(); i++)
        {
            tempTree->addNode(c[i].getLastName(), c[i]);
        }
    }
    else if (option == 4)
    {
        //sort the vector
        cout << "Sorting the database..." << endl << endl;
        
        //add vector to database
        for (int i = 0; i < c.size(); i++)
        {
            tempTree->addNode(c[i].getNickName(), c[i]);
        }
    }
    else if (option == 5)
    {
        //sort the vector
        cout << "Sorting the database..." << endl << endl;
        
        //add vector to database
        for (int i = 0; i < c.size(); i++)
        {
            tempTree->addNode(c[i].getHeight(), c[i]);
        }
    }
    
    else if (option == 6)
    {
        //sort the vector
        cout << "Sorting the database..." << endl << endl;
        
        //add vector to database
        for (int i = 0; i < c.size(); i++)
        {
            tempTree->addNode(c[i].getWeight(), c[i]);
        }
    }
    
    else if (option == 7)
    {
        //sort the vector
        cout << "Sorting the database..." << endl << endl;
        
        //add vector to database
        for (int i = 0; i < c.size(); i++)
        {
            tempTree->addNode(c[i].getReach(), c[i]);
        }
    }
    
    else if (option == 8)
    {
        //sort the vector
        cout << "Sorting the database..." << endl << endl;
        
        //add vector to database
        for (int i = 0; i < c.size(); i++)
        {
            tempTree->addNode(c[i].getStance(), c[i]);
        }
    }
    
    else if (option == 9)
    {
        //sort the vector
        cout << "Sorting the database..." << endl << endl;
        
        //add vector to database
        for (int i = 0; i < c.size(); i++)
        {
            tempTree->addNode(c[i].getWins(), c[i]);
        }
    }
    
    else if (option == 10)
    {
        //sort the vector
        cout << "Sorting the database..." << endl << endl;
        
        //add vector to database
        for (int i = 0; i < c.size(); i++)
        {
            tempTree->addNode(c[i].getLosses(), c[i]);
        }
    }
    else if (option == 11)
    {
        //sort the vector
        cout << "Sorting the database..." << endl << endl;
        
        //add vector to database
        for (int i = 0; i < c.size(); i++)
        {
            tempTree->addNode(c[i].getDraws(), c[i]);
        }
    }
    else if (option == 12)
    {
        //sort the vector
        cout << "Sorting the database..." << endl << endl;
        
        //add vector to database
        for (int i = 0; i < c.size(); i++)
        {
            tempTree->addNode(c[i].getTotalFights(), c[i]);
        }
    }    
    //return the sorted tree
    return tempTree;
}




#endif /* functions_h */
