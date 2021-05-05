
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
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#Using the Program">Using the Program</a></li>       
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#purpose">Purpose</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgements">Acknowledgements</a></li>
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
*  A C++ compiler must also be installed.  This program was written using g++, which can be installed on linux systems using the below command.
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
   $ g++ -std=c++11 -Wall main.cpp BSTree.cpp MMAFighters.cpp -o prog
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

### Use the Program

<p>The rest of the program is self-explanatory based on the menu prompts.  There is a main menu that allows you to read in fighter data, (provided it is a CSV with the proper columns), search for a fighter record (either exact search or contains search), modify a fighter record, delete a fighter record, sort the records, display all of the records or save the records to a file, which can be subsequently loaded back into the program at a later time.  This allows you to save your work if you have done any modification of the records from the csv file.</p>

<!-- ROADMAP -->
## Roadmap

See the [open issues](https://github.com/davidshawver/finalprojectCSC212/issues) for a list of proposed features (and known issues).


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

