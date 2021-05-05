/*
 
 
 */

#ifndef Menu_h
#define Menu_h

#include "functions.h"
#include "MMAFighters.h"
#include "BSTree.h"
#include "Node.h"
#include <string>
#include <fstream>


using namespace std;

void Menu()
{
    
    MMAFighters MMAFighter;   //create MMAFighters object
    int selection;      //holds user menu selection
    string file;        //holds file name
    string fieldSearch;
    BSTree *currentTree = new BSTree;
    Node *node = new Node;
    
cout <<     "------------------------------------------" << endl << endl;
    
cout <<"            ,.        \n" ;
cout <<"             \\-'__    \n"  ;
cout <<"            / o.__o____\n";
cout <<"            \\/_/ /.___/--,\n";
cout <<"              ||\' \n";
cout <<"              | /\n";
cout <<"              \\_\\"<<endl;
cout <<"              -''\n\n";


    cout << "------------------------------------------\n" << endl;
    cout << "\t\tWelcome!\n" << endl;
    cout << "This program allows you to load, create, and manage your own";
    cout << " MMA Fighter Database!\n" << endl;

    
    do
    {
        //Display menu options for user
        cout << "\t\tMAIN MENU" << "\n\n";
        cout << "1. Read Data into the MMA Fighter Database.  "<< endl;
        cout << "2. Insert a new Fighter Record" << endl;
        cout << "3. Search for a Fighter Record" << endl;
        cout << "4. Modify a Fighter Record" << endl;
        cout << "5. Delete a Fighter Record" << endl;
        cout << "6. Sort Fighter Records" << endl;
        cout << "7. Display Fighter Records" << endl;
        cout << "8. Save Records to File" << endl;
        cout << "9. Quit Program" << endl << endl;
        cout << "Selection: ";
        cin >> selection;
        cout << endl;
        
        switch (selection)
        {
            //read input from file
            case 1:
                //prompts user to enter the name of the file
                //call function readFromFile()
                readFromFile(currentTree);
                break;
            case 2:
                //call addRecord() function
                addRecord(currentTree);
                break;
            case 3:
                search(currentTree);
                break;
            case 4:
                //call modify_Record() function
                currentTree = modify_Record(currentTree);
                break;
            case 5:
                //call deleteRecord() function
                currentTree = delete_Record(currentTree);
                break;
            case 6:
                //call sortRecord() function
                currentTree = sort_Records(currentTree);
                break;
            case 7:
                //calls displayRecords function
                displayRecords(currentTree);
                break;
            case 8:
                //call saveToFile() function
                save(node, currentTree, file);
                break;
            //exit program
            case 9:
                cout << "Goodbye!" << endl;
                delete currentTree;
                break;
            //input validation
            default:
                cout << "Invalid selection! Please try again" << endl << endl;
                break;
                
        }
        
    } while (selection != 9);   //repeat menu options unless user selects option 8
    
}



#endif /* Menu_h */
