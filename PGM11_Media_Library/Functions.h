#pragma once
#include <fstream>
#include <iostream>
#include<vector>

#include "Media.h"

using namespace std;

int readMediaList(ifstream& inFile, ofstream& outErr, vector<Media>& m);
//PRE: files are open in main and acessible
//POST: reads the data from the csv file, pushes the objects into a vector<Media>
//produces an error report of any records that have errors


bool isDigits(string str1);
//PRE: reads a string
//POST: returns true or false based on if the string contains only 0-9 and/or '-' negative sign


void printMovieList(ofstream& outFile, ofstream& outErr, vector<Media>& m, vector<string> row);
//PRE: accepts outFile, outErr, mediaInfo vector, and current row
//POST: writes movie information to outFile, errors to outErr based on input in the current row vector


void printBookList(ofstream& outFile, ofstream& outErr, vector<Media>& m, vector<string> row);
//PRE: accepts outFile, outErr, mediaInfo vector, and current row
//POST: writes book information to outFile, errors to outErr based on input in the current row vector

void printSongList(ofstream& outFile, ofstream& outErr, vector<Media>& m, vector<string> row);
//PRE: accepts outFile, outErr, mediaInfo vector, and current row
//POST: writes song information to outFile, errors to outErr based on input in the current row vector

void printAllMedia(ofstream& outFile, ofstream& outErr, vector<Media>& m, vector<string> row);
//PRE: media list is loaded with valid values, mediaCommands also loaded and verified
//POST: writes all media information to the report file, errors to outErr

void addNewMedia(ofstream& outFile, ofstream& outErr, vector<Media>& m, vector<string> row);
//PRE: media list is loaded with valid values, first char in input stream has been read
//POST: will read input string and separate all values into a vector<string> row; media record is pushed onto the vector and counts are updated

void printTotals(ofstream& outFile);
//PRE: static array initialized to 0
//POST: prints the total count of movies, books, and songs in your library
//(HINT: use static class array, update as file is read and items are added to the vector)
