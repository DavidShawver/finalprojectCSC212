
<p>David Shawver<br />
CSC 212 Final Project<br />
May 6, 2021<br />
</p>
<br />
<br />

<p align="center"><img src="https://github.com/DavidShawver/finalprojectCSC212/blob/master/assets/UFC.jpg" width="400" height="220" alt="UFC Logo"></p>
<p align="center">
  <a href="https://github.com/davidshawver/finalprojectCSC212">
  </a>
</p>
  <h1 align="center" style="font-size:40px">Simple Database for Basic MMA Fighter Info</h1>

  <p align="left"><ul><li>
    A simple database that allows you to load, create, search, sort, save, and modify records of basic MMA fighter data such as name, nickname, height, weight, and reach
  </li><li>Explore the
  <a align="center" href="https://github.com/davidshawver/finalprojectCSC212/"><strong> docs</strong></a></li></ul>
    <br />
  </p>
</p>



<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary><h2 style="display: inline-block">Table of Contents</h2></summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#Purpose">Purpose</a>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
        <li><a href="#load-the-csv-files">Load the CSV Files</a></li>
        <li><a href="#use-the-program">Use the Program</a></li> 
      </ul>
    </li>
    <li><a href="#purpose">Purpose</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
# About The Project

<!-- USAGE EXAMPLES -->
## Purpose

This program allows a user, perhaps a fan off Mixed Martial Arts (MMA), to load basic data characteristics of the various MMA Fighters into a database for easy manipulation and retrieval of records.  The database could ultimately be used with other code and further development to generate an MMA Fighter info API that could serve as a rolodex supplying information kind of like a baseball card for use by web site or game creators.  The database is simple, but could easily be expanded to include additional data categories.  The basic name, physical characteristic, and fighter record information is all that has been currently programmed in due to accessibility and availability of data, but additional info such as age, knockout statistics, fighting style, and takedown statistics could be added as a future feature of the program.

<!-- GETTING STARTED -->
# Getting Started

To get a local copy up and running follow these simple steps.

### Prerequisites
*  Ability to run a bash shell
*  A C++ compiler must also be installed.  This program was written using g++. This compiler can be installed on linux systems using the below command.
  ```sh
  $ sudo apt install build-essential
  ```

## Using the Program

### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/davidshawver/finalprojectCSC212.git
   ```
2. Run make file:
   ```sh
   make
   ```
   Or use the below commands:
   ```sh
   $ g++ -std=c++11 -Wall main.cpp BSTree.cpp MMAFighters.cpp -o prog && ./prog
   ```
### Load the CSV Files

Two sample CSV files are included in this repository to try the program
<table style="width:100%">
  <tr>
    <th>Filename</th>
    <th>Contains</th>
  </tr>
  <tr>
    <td><a href="https://github.com/DavidShawver/finalprojectCSC212/blob/master/fightmetric.csv">fightmetric.csv</a></td>
    <td>All 2857 fighters<td>
  </tr>
  <tr>
    <td><a href="https://github.com/DavidShawver/finalproject.CSC212/blob/master/fightmetricsmaller.csv">fightmetricsmaller.csv</a></td>
    <td>Partial database of only 400 fighters</a>
  </tr>
</table>
<br />
The data are from a database which includes every UFC fighter since the league was formed.  Updated web-scraper CSV files with new fighers and updated wins and losses can always be downloaded <a href="https://www.dropbox.com/s/o88087phvf9veow/fightmetric.csv?dl=0"> from here</a>, but will require the reordering of columns and removal of all columns after column 10 (can be done using Microsoft excel or Google sheets).</p>
<p>Once the program has loaded from the make file, a menu appears.  Select the first option to load from file.</p>
<p align="center"><img src="https://github.com/DavidShawver/finalprojectCSC212/blob/master/assets/SS1.png" width="500" height="300" alt="menu screenshot"></p>

<p>Next, since we are not loading from a saved file that is generated from the program, we want to select option 1 to load the data from a csv file.  Next, type in the name of the csv which you want to load and is in the project folder (in this case fightmetric.csv) and press enter.  Your CSV records should now be loaded into the database!  You can next choose whether to display the records on the screen and you are taken back to the main menu.  Note that the program does not currently support loading a file to add records to those currently in the database, and will instead replace all of the records currently loaded in when a new CSV file or saved file is loaded.</p>
<p align="center"><img src="https://github.com/DavidShawver/finalprojectCSC212/blob/master/assets/SS2.png" width="500" height="300" alt="menu screenshot"></p>

### Use

<p>The rest of the program is self-explanatory based on the menu prompts.  There is a main menu that allows you to read in fighter data, (provided it is a CSV with the proper columns), search for a fighter record (either exact search or contains search), modify a fighter record, delete a fighter record, sort the records, display all of the records or save the records to a file, which can be subsequently loaded back into the program at a later time.  This allows you to save your work if you have done any modification of the records from the csv file.</p>

### Design/Code Overview
There are three major classes form the overall structure of the program, the AVL Tree, which is constituted of Nodes from the Node class, and the MMAFighter  class.  The MMAFighters class is placed in each Node object along with a string key for the AVL self-balancing Tree, which is an arbitrary and distinct Fighter number from the fightmetric data.

The key, and all of the data members in the MMAFighters class are strings.  In order to facilitate numerical comparisons that the program requires, a function called isLessThanOtherKey converts the string data to an int. It knows whether the string type data should be a number in part based on a boolean flag data member created as part of the AvlTree class.  This switch is set to true when the program is working with the key or with the numeric data members in order to do anythign that requires the use of the insert or delete functions.  These functions are used for almost every functionality of the program including sort, search, modify, add record, and save.

As a type of binary search tree, the AVL tree is sorted after nodes have been inserted.  So when sorting by the key all that typically has to be done is printing inOrder.  However, when the user wishes to sort by another data member, such as name, or weight, the program accomplishes this by placing all of the fighter objects in a vector and reconstituting the tree with the insert function, using the particular data member as the first parameter (i.e., as the key) instead of the "Key" data member that is used by default.  The tree pointer in the main menu is then switched to this newly reconstituted tree, which stays in this sorted formation until the formation is changed again.

Binary Search is generally not done in the program do to the complexity of having to update a separate tree for each category of search.  Binary Search is normally the best type of search due to its O(log n) time complexity.  It's not really necessary for this size dataset.  

However, as part of the exercise of demonstrating Binary Search, one aspect of search is now binary search, the ExactSearch for fighter number, demonstrated in the BinarySearchDemonstration() function.  For the rest of the searches I just recursively checked every node through the AVL tree.

Modifying or deleting a record utilizes the search function to get the proper node.  It creates a temporary tree with every result from the search and passes the root node.  The user may have to do an "exact" search, in order to get the exact record they are looking to modify or delete.

I researched how to put together my "delete" function for the AVL tree online.  There still seems to be a bug that deletes the entire tree sometimes.

Saving to file is simply done by printing to file inOrder.  The data can then be read back in by a special function "readSavedFile" that has been fashioned to read data in that format.  The user can simply "save", in which case the file is named "outfile.txt" or "outfile1.txt1", etc. if there already is an outfile.txt.  Or the user can "save As", in which case the user must specify a filename that does not exist in the current folder.

The program begins on a menu that allows to user to determine what to do and calls other functions.  The user must generally start by adding their own data or loading a file.  Most of the functions that run the program are in the functions.h file.  

### Data Structures Used/ Mastery Topics

I am seeking mastery in the following topics:

-Balanced Trees
-Binary Search
-Binary Search Tree Implementation and Analysis
-Dynamic Arrays (Std vector class)
-Linked List

AVL TREE/BALANCED TREES

The AVL tree is a self-balancing tree and includes the major functions of insert and delete.  The self-balancing aspect ensures O(logn) complexity  and that the tree does not become unbalanced resulting in a O(n) time complexity for search, insert, and delete.

A balanced tree such as an AVL tree or a red black tree are most appropriate for making a database like this since they speed up the functions and save computing power.  

An AVL tree tends to rebalance more often than a red black tree which provides a more balanced tree and faster lookups.  This makes them ideal for Databases where faster retrievals are required.  They require a tiny bit more storage than a red black tree (1 bit per node).  Red black trees can offer faster insertion or removal, but on net AVL trees are better suited for databases such as this one.

I believe that my implementation of such a complicated tree class demonstrates that I have mastery of the topic of balanced trees.

BINARY SEARCH

Binary search is a mainstay of modern search functions.  It is clearly most appropriate for databases in order to have a fast search.  Although my database is not that big, it is good to have the option of knowing how to implement binary search if the database becomes a lot bigger or slower.  As mentioned previously, the worst case time complexity is O(logn) for a balanced binary tree.  The worst case time complexity for an unbalanced binary tree is O(n).  However, since I have implemented an AVL tree, my worst case time complexity will be O(logn).

BINARY SEARCH ANALYSIS

I previously covered the worst case time complexity above.  Although my function may have some extra lines of code that I added as I was debugging including calling a function to convert from string datatype to int for quantitative comparison, these are only add linear work and would not affect the asymptotic worst case time complexity.

I am seeking mastery on both Binary Search and Binary Search Analysis.  I believe that my choice of Binary Search Tree for my search algorithm demonstrates that I understand the time complexity issues and know how to implement BST's.

DYNAMIC ARRAYS

I also used vectors in this implementation.  Vectors are the standard library implementation of dynamic arrays.  A vector was used to hold all of the Node objects while they were being reorganized into a new tree for sorting purposes.  They were most convenience for this purpose since the size did not have to be known beforehand.  Although the MMA data tends to be less than 3000 entries, for the purposes of my database, in which the database is not huge, vectors were most convenient.  The random access was also most convenient due to the way that I iterated through while loops to do operations to every data member of the MMAFighters class.  Vectors allow random access with O(1) for each until resizing is needed.  Dynamic arrays have an amortized cost of O(1) for appending as well.

LINKED LIST

In implementing my Avl tree class I of course used linked lists.  A linked list was appropriate for this purpose because although you could also use an array like a vector, binary search trees that must support insertion and removal at particular places in the tree tend to be much easier wtih linked lists than arrays.  It would certainly be confusing to try and calculate the proper parent and siblings nodes with such a complicated balanced tree implementation and then translate it all into code.  In an array, all of the data is in adjacent memory blocks.  This makes it more costly to adjust the size.  In a linked list, the memory can all be scattered because pointers can always be readjusted, so the size does not need to be known beforehand.  Linked lists can use more memroy since a reference to the next node is also stored along with the data.  However, dynamic arrays also allocate memory at runtime.  One downside to linked lists tends to be that you cannot randomly access a particular element in the list without traversing through the entire array.  In my implementation this did not end up being an issue since with binary search needed elements can also be found with O(logn) complexity.  INserting a new element is something that has to be done often with an AVL tree since it is constantly being readjusted.  This would definitely be more difficult to do with arrays since more room has to be created for the new elements forcing all teh subsequent elements to be shifted.  Essentially the dynamic resizing and ease of insertion are the two reasons why I perfer linkedlists for my implementation.

### Potential Bugs

The program still has a few bugs.  The most serious one is that the delete function sometimes deletes the entire tree of data.  Other than that there is certain menu behavior that i would like to improve.  When you accidentally hit '2' in the menu the program makes you enter in a new MMA fighter even if it was a mistake.  That is easily fixed and I will do so as soon as I have more time.

### Easter Eggs

I made a feature that checks if the filename you want to give already exists in the folder.  It then prompts you to change the filename.  It does the same thing for "Save," in which it titles the file "Outfile.txt" and increments by 1 for each "Outfile" that already exists in the folder.

### Group

I created this project completely on my own, but did consult online for how to do an AVL tree and how to set up a program such as this one, and a few other things.  I added ASCI art of a karate man for the menu.  I also learned how to use Git and Github for this project and created a readme.MD file, which has links and pictures for the project's Github page.

### Topic Overview

I believe the complexity of my project demonstrates mastery for the topics that I listed above:-Balanced Trees, Binary Search, Binary Search Tree Implementation and Analysis, Dynamic Arrays (Std vector class), amd Linked Lists.



<!-- CONTACT -->
## Contact

Your Name - [@davidshawver1875](https://twitter.com/davidshawver1875) - david.a.shawver@gmail.com

Project Link: [https://github.com/davidshawver/finalprojectCSC212](https://github.com/davidshawver/finalprojectCSC212)

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/othneildrew/Best-README-Template.svg?style=flat-square
[contributors-url]: https://github.com/davidshawver/finalprojectCSC212/graphs/contributors
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/davidshawver

