#include <iostream>
#include <iomanip>
#include <string>
#include <iostream>

#include "Media.h"


using namespace std;

//default constructor
Media::Media() {
	type = ' ';
	title = " ";
	keyName = " ";
	rating = 0;
	genre = " ";
	length = 0;
	yearReleased = 0;
}

//overloaded constructor
Media::Media(char tP, string t, string kN, int r, string g, int l, int yR) {
	type = tP;
	title = t;
	keyName = kN;
	rating = r;
	genre = g;
	length = l;
	yearReleased = yR;
}



//getters
char Media::getType() { return type; }
string Media::getTitle() { return title; }
string Media::getKeyName() { return keyName; }
int Media::getRating() { return rating; }
string Media::getGenre() { return genre; }
int Media::getLength() { return length; }
int Media::getYearReleased() { return yearReleased; }

//setters
void Media::setType(char tP) { type = tP; };
void Media::setTitle(string t) { title = t; }
void Media::setKeyName(string kN) { keyName = kN; }
void Media::setRating(int r) { rating = r; }
void Media::setGenre(string g) { genre = g; }
void Media::setLength(int l) { length = l; }
void Media::setYearReleased(int yR) { yearReleased = yR; }

//initalize static class array to 0
int Media::mediaCount[3] = { 0 };

/*void printCounts(ofstream& outFile) {
	
	//write headings to outFile
	outFile << "\n" << endl;
	outFile << setfill('+') << setw(50);
	outFile << "\n\tYOUR MEDIA LIBRARY\n" << endl;

	outFile << "#" << "\tTYPE" << endl;
	outFile << Media::mediaCount[0] << "\tMovies" << endl;
	outFile << Media::mediaCount[1] << "\tBooks" << endl;
	outFile << Media::mediaCount[2] << "\tSongs" << endl;

	int totalMedia = Media::mediaCount[0] + Media::mediaCount[1] + Media::mediaCount[2];

	outFile << totalMedia << "\tItems" << endl;

	outFile << "\n\n" << endl;
}*/