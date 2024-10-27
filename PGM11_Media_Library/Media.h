#pragma once

#include <string>
#include <iomanip>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Media {

protected:
	char type;
	string title;
	string keyName;
	int rating;
	string genre;
	int length;
	int yearReleased;

public:
	Media();
	Media(char tP, string t, string kN, int r, string g, int l, int yR);


	//getters
	char getType();
	string getTitle();
	string getKeyName();
	int getRating();
	string getGenre();
	int getLength();
	int getYearReleased();

	//setters
	void setType(char tP);
	void setTitle(string t);
	void setKeyName(string kN);
	void setRating(int r);
	void setGenre(string g);
	void setLength(int l);
	void setYearReleased(int yR);

	//static class array to be keep track of different media types
	static int mediaCount[3];

	static void increaseCount(int i) {
		mediaCount[i]++;
	}

	//void printCounts(ofstream& outFile);

};