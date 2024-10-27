// PGM11: Media_Library.cpp
// NAME: Marie Biernacki

#include "Media.h"
#include "Functions.h"

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

int main()
{
    //create an empty vector of Media type
    vector<Media> mediaInfo;


    //OPEN mediaList.txt, mediaCommands.txt, outfile for report, outfile for errors

    ifstream mediaFile;
    mediaFile.open("mediaList.txt");
    if (!mediaFile.is_open()) {
        cout << "ERROR: Unable to open mediaList.txt " << endl;
    }

    ifstream mediaC;
    mediaC.open("mediaCommands.txt");
    if (!mediaC.is_open()) {
        cout << "ERROR: Unable to open mediaCommands.txt " << endl;
    }

    ofstream reportFile;
    reportFile.open("mediaReport.txt");
    if (!reportFile.is_open()) {
        cout << "ERROR: Unable to open mediaReport.txt " << endl;
    }

    ofstream errorFile;
    errorFile.open("mediaError.txt");
    if (!errorFile.is_open()) {
        cout << "ERROR: Unable to open mediaError.txt " << endl;
    }


    //LOAD media vector with objects
    readMediaList(mediaFile, errorFile, mediaInfo);



    //SOURCE: base for reading mediaCommands from program 10
    
    //READ mediaCommands to determine the next steps
    //set temporary variables for getting information
    string inRec, tempStr;
    vector<string> row;

    //initialize while loop read through mediaC, line by line
    while (getline(mediaC, inRec)) {

        stringstream inSS(inRec);
        row.clear();
        
        //parse through the string, using comma as a delimeter
        //add individual elements to the row vector
        while (getline(inSS, tempStr, ',')) {
            row.push_back(tempStr);
        }

        //if M is read into the file, CALL printMovieList
        if (row[0][0] == 'M') {
            printMovieList(reportFile, errorFile, mediaInfo, row);
        }

        else if (row[0][0] == 'B') {
            printBookList(reportFile, errorFile, mediaInfo, row);
        }

        else if (row[0][0] == 'A') {
            printAllMedia(reportFile, errorFile, mediaInfo, row);
        }

        else if (row[0][0] == 'S') {
            printSongList(reportFile, errorFile, mediaInfo, row);
        }

        else if (row[0][0] == 'N') {
            addNewMedia(reportFile, errorFile, mediaInfo, row);
        }
        //FIXME check with Prof
        else if (row[0][0] == 'T') {
            printTotals(reportFile);
        }

        else if (row[0][0] == 'Q') {
            break;
        }

        else {
            errorFile << "\nThe command: " << row[0][0] << " is invalid." << endl;
        }
          
        
    }



    //close files
    mediaFile.close();
    mediaC.close();
    reportFile.close();
    errorFile.close();

}

