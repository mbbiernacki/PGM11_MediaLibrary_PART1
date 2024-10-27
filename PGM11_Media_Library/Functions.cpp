
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <stdexcept>


#include "Functions.h"



//SOURCE: isDigits from in class work/previous programs
bool isDigits(string str1) {
	return (str1.find_first_not_of("-0123456789") == string::npos);
}


//SOURCE: readMediaList base from program 10 readFile function
int readMediaList(ifstream& inFile, ofstream& outErr, vector<Media>& m) {
	
	//set temporary variables for getting information
	string inRec, tempStr;
	vector<string> row;

	//initialize while loop to loop through inFile
	while (getline(inFile, inRec)) {
	
		stringstream inSS(inRec);
		row.clear();

		while (getline(inSS, tempStr, ',')) {
			row.push_back(tempStr);
		}

		try {
			if (row[0][0] == 'M') {
				
				
				if (!isDigits(row[3]) || !isDigits(row[5]) || !isDigits(row[6])) {
					throw runtime_error(
						"ERROR: " + row[0] + "," + row[1] + "," + row[2] + "," + row[3] + "," + row[4] + "," + row[5] + "," + row[6] +
						"\nPrevious record has an invalid stoi argument error");
				}
				else if (stoi(row[3]) < 1 || stoi(row[3]) > 10) {
					throw runtime_error (
						"ERROR: " + row[0] + "," + row[1] + "," + row[2] + "," + row[3] + "," + row[4] + "," + row[5] + "," + row[6] +
						"\nThere was an invalid value entered for rating");
				}
				else if (stoi(row[6]) < 1500 || stoi(row[6]) > 2023) {
					throw runtime_error(
						"ERROR: " + row[0] + "," + row[1] + "," + row[2] + "," + row[3] + "," + row[4] + "," + row[5] + "," + row[6] +
						"\nThere was an invalid value entered for year");
				}
				
				Media movie('M', row[1], row[2], stoi(row[3]), row[4], stoi(row[5]), stoi(row[6]));
				m.push_back(movie);

				//increase movie count
				Media::increaseCount(0);

			}
			
			else if (row[0][0] == 'B') {
				

				if (!isDigits(row[3]) || !isDigits(row[5]) || !isDigits(row[6])) {
					throw runtime_error(
						"ERROR: " + row[0] + "," + row[1] + "," + row[2] + "," + row[3] + "," + row[4] + "," + row[5] +
						"\nPrevious record has an invalid stoi argument error");
				}
				else if (stoi(row[3]) < 1 || stoi(row[3]) > 10) {
					throw runtime_error(
						"ERROR: " + row[0] + "," + row[1] + "," + row[2] + "," + row[3] + "," + row[4] + "," + row[5] +
						"\nThere was an invalid value entered for rating");
				}
				else if (stoi(row[6]) < 1500 || stoi(row[6]) > 2023) {
					throw runtime_error(
						"ERROR: " + row[0] + "," + row[1] + "," + row[2] + "," + row[3] + "," + row[4] + "," + row[5]+
						"\nThere was an invalid value entered for year");
				}
				Media book('B', row[1], row[2], stoi(row[3]), row[4], stoi(row[5]), stoi(row[6]));
				m.push_back(book);
				
				//increase book count
				Media::increaseCount(1);
			}
			else if (row[0][0] == 'S') {
				

				if (!isDigits(row[3]) || !isDigits(row[5]) || !isDigits(row[6])) {
					throw runtime_error(
						"ERROR: " + row[0] + "," + row[1] + "," + row[2] + "," + row[3] + "," + row[4] + "," + row[5] + "," + row[6] +
						"\nPrevious record has an invalid stoi argument error");
				}
				else if (stoi(row[3]) < 1 || stoi(row[3]) > 10) {
					throw runtime_error(
						"ERROR: " + row[0] + "," + row[1] + "," + row[2] + "," + row[3] + "," + row[4] + "," + row[5] + "," + row[6] +
						"\nThere was an invalid value entered for rating");
				}
				else if (stoi(row[6]) < 1500 || stoi(row[6]) > 2023) {
					throw runtime_error(
						"ERROR: " + row[0] + "," + row[1] + "," + row[2] + "," + row[3] + "," + row[4] + "," + row[5] + "," + row[6] +
						"\nThere was an invalid value entered for year");
				}
				Media song('S', row[1], row[2], stoi(row[3]), row[4], stoi(row[5]), stoi(row[6]));
				m.push_back(song);

				//increase song count
				Media::increaseCount(2);
			}
		}
		catch (runtime_error e) {
			outErr << e.what() << endl;
			outErr << "\n\n" << endl;
		}
		
		catch (...) {
			outErr << "unknown error found" << endl;
		}
	}
	return 0;
}


void printMovieList(ofstream& outFile, ofstream& outErr, vector<Media>& m, vector<string> row) {

	

	//length of the row vector determines what happens next
	if (row.size() == 1) {


		//write headings to outFile
		outFile << "\n" << endl;
		outFile << setfill('+') << setw(50);
		outFile << "\n\tYOUR MOVIE LIST\n" << endl;

		outFile << "#" << "\tTITLE" << "\t\tYEAR" << "\tRATING" << endl;

		int count = 1;
		for (int i = 0; i < m.size(); i++) {
			if (m[i].getType() == 'M') {
				outFile << count << "\t" << m[i].getTitle() << "\t" << m[i].getYearReleased() << "\t" << m[i].getRating() << endl;
			}
			count += 1;
		}
	
	}

	else if (row.size() == 2) {

		if (isDigits(row[1])) {

			try {
				
				if (stoi(row[1]) < 1 || stoi(row[1]) > 10) {
					throw runtime_error("\nUnable to process command. The rating of: " + row[1] + " is invalid.");
				}

				else {

					//write headings to outFile
					outFile << "\n" << endl;
					outFile << setfill('+') << setw(50);
					outFile << "\n\tYOUR MOVIE LIST\n" << endl;

					outFile << "#" << "\tTITLE" << "\t\tYEAR" << "\tRATING" << endl;

					//iterate through media vector and only print movies with value greater than or equal to rating provided
					int count = 1;
					for (int i = 0; i < m.size(); i++) {
						if (m[i].getType() == 'M' && m[i].getRating() >= stoi(row[1]))
							outFile << count << "\t" << m[i].getTitle() << "\t" << m[i].getYearReleased() << "\t" << m[i].getRating() << endl;
						count += 1;
					}
				}
			}
			
			catch(runtime_error e){
				outErr << e.what() << endl;
			}
		}
		else {

			int count = 1;
			bool doesNotExist = true;
			for (int i = 0; i < m.size(); i++) {
				if (m[i].getType() == 'M' && m[i].getGenre() == row[1]) {
					//outFile << count << "\t" << m[i].getTitle() << "\t" << m[i].getYearReleased() << "\t" << m[i].getRating() << "\t" << m[i].getGenre() << endl;
					doesNotExist = false;
				}
				count += 1;
			}

			if (doesNotExist) {
				outErr << "\nUnable to process command. There was not item of genre: " << row[1] << " in your list." << endl;
			}
			else {
			
				//write headings to outFile
				outFile << "\n" << endl;
				outFile << setfill('+') << setw(50);
				outFile << "\n\tYOUR MOVIE LIST\n" << endl;

				outFile << "#" << "\tTITLE" << "\t\tYEAR" << "\tRATING" << "\tGENRE" << endl;

				int count = 1;
				
				for (int i = 0; i < m.size(); i++) {
					if (m[i].getType() == 'M' && m[i].getGenre() == row[1]) {
						outFile << count << "\t" << m[i].getTitle() << "\t" << m[i].getYearReleased() << "\t" << m[i].getRating() << "\t" << m[i].getGenre() << endl;
					}
					count += 1;
				}
			}
		}
	}
	
}


void printBookList(ofstream& outFile, ofstream& outErr, vector<Media>& m, vector<string> row) {



	//length of the row vector determines what happens next
	if (row.size() == 1) {


		//write headings to outFile
		outFile << "\n" << endl;
		outFile << setfill('+') << setw(50);
		outFile << "\n\tYOUR BOOK LIST\n" << endl;

		outFile << "#" << "\tTITLE" << "\t\tYEAR" << "\tRATING" << endl;

		int count = 1;
		for (int i = 0; i < m.size(); i++) {
			if (m[i].getType() == 'B') {
				outFile << count << "\t" << m[i].getTitle() << "\t" << m[i].getYearReleased() << "\t" << m[i].getRating() << endl;
			}
			count += 1;
		}

	}

	else if (row.size() == 2) {

		if (isDigits(row[1])) {


			try {

				if (stoi(row[1]) < 1 || stoi(row[1]) > 10) {
					throw runtime_error("\nUnable to process command. The rating of: " + row[1] + " is invalid.");
				}

				else {

					//write headings to outFile
					outFile << "\n" << endl;
					outFile << setfill('+') << setw(50);
					outFile << "\n\tYOUR BOOK LIST\n" << endl;

					outFile << "#" << "\tTITLE" << "\t\tYEAR" << "\tRATING" << endl;

					//iterate through media vector and only print movies with value greater than or equal to rating provided
					int count = 1;
					for (int i = 0; i < m.size(); i++) {
						if (m[i].getType() == 'B' && m[i].getRating() >= stoi(row[1]))
							outFile << count << "\t" << m[i].getTitle() << "\t" << m[i].getYearReleased() << "\t" << m[i].getRating() << endl;
						count += 1;
					}
				}
			}

			catch (runtime_error e) {
				outErr << e.what() << endl;
			}
		}
		else {

	
			bool doesNotExist = true;
			for (int i = 0; i < m.size(); i++) {
				if (m[i].getType() == 'B' && m[i].getGenre() == row[1]) {
					doesNotExist = false;
				}
			}

			if (doesNotExist == true) {
				outErr << "\nUnable to process command. There was not item of genre: " << row[1] << " in your list." << endl;
			}
			else {

				//write headings to outFile
				outFile << "\n" << endl;
				outFile << setfill('+') << setw(50);
				outFile << "\n\tYOUR BOOK LIST\n" << endl;

				outFile << "#" << "\tTITLE" << "\t\tYEAR" << "\tRATING" << "\tGENRE" << endl;

				int count = 1;
				for (int i = 0; i < m.size(); i++) {
					if (m[i].getType() == 'B' && m[i].getGenre() == row[1]) {
						outFile << count << "\t" << m[i].getTitle() << "\t" << m[i].getYearReleased() << "\t" << m[i].getRating() << "\t" << m[i].getGenre() << endl;
					}
					count += 1;
				}
			}

		}

	}
}


void printSongList(ofstream& outFile, ofstream& outErr, vector<Media>& m, vector<string> row) {



	//length of the row vector determines what happens next
	if (row.size() == 1) {


		//write headings to outFile
		outFile << "\n" << endl;
		outFile << setfill('+') << setw(50);
		outFile << "\n\tYOUR SONG LIST\n" << endl;

		outFile << "#" << "\tTITLE" << "\t\tYEAR" << "\tRATING" << endl;

		int count = 1;
		for (int i = 0; i < m.size(); i++) {
			if (m[i].getType() == 'S') {
				outFile << count << "\t" << m[i].getTitle() << "\t" << m[i].getYearReleased() << "\t" << m[i].getRating() << endl;
			}
			count += 1;
		}

	}

	else if (row.size() == 2) {

		if (isDigits(row[1])) {


			try {

				if (stoi(row[1]) < 1 || stoi(row[1]) > 10) {
					throw runtime_error("\nUnable to process command. The rating of: " + row[1] + " is invalid.");
				}

				else {

					//write headings to outFile
					outFile << "\n" << endl;
					outFile << setfill('+') << setw(50);
					outFile << "\n\tYOUR SONG LIST\n" << endl;

					outFile << "#" << "\tTITLE" << "\t\tYEAR" << "\tRATING" << endl;

					//iterate through media vector and only print songs with value greater than or equal to rating provided
					int count = 1;
					for (int i = 0; i < m.size(); i++) {
						if (m[i].getType() == 'S' && m[i].getRating() >= stoi(row[1]))
							outFile << count << "\t" << m[i].getTitle() << "\t" << m[i].getYearReleased() << "\t" << m[i].getRating() << endl;
						count += 1;
					}
				}
			}

			catch (runtime_error e) {
				outErr << e.what() << endl;
			}
		}
		else {


			bool doesNotExist = true;
			for (int i = 0; i < m.size(); i++) {
				if (m[i].getType() == 'S' && m[i].getGenre() == row[1]) {
					doesNotExist = false;
				}
			}

			if (doesNotExist == true) {
				outErr << "\nUnable to process command. There was not item of genre: " << row[1] << " in your list." << endl;
			}
			else {

				//write headings to outFile
				outFile << "\n" << endl;
				outFile << setfill('+') << setw(50);
				outFile << "\n\tYOUR SONG LIST\n" << endl;

				outFile << "#" << "\tTITLE" << "\t\tYEAR" << "\tRATING" << "\tGENRE" << endl;

				int count = 1;
				for (int i = 0; i < m.size(); i++) {
					if (m[i].getType() == 'S' && m[i].getGenre() == row[1]) {
						outFile << count << "\t" << m[i].getTitle() << "\t" << m[i].getYearReleased() << "\t" << m[i].getRating() << "\t" << m[i].getGenre() << endl;
					}
					count += 1;
				}
			}

		}

	}
}


void printAllMedia(ofstream& outFile, ofstream& outErr, vector<Media>& m, vector<string> row) {
	
	//length of the row vector determines what happens next
	if (row.size() == 1) {


		//write headings to outFile
		outFile << "\n" << endl;
		outFile << setfill('+') << setw(50);
		outFile << "\n\tYOUR MEDIA LIST\n" << endl;

		outFile << "#" << "\tTITLE" << "\t\tYEAR" << "\tRATING" << "\tTYPE" << endl;

		int count = 1;
		for (int i = 0; i < m.size(); i++) {
			outFile << count << "\t" << m[i].getTitle() << "\t"
				<< m[i].getYearReleased() << "\t"
				<< m[i].getRating() << "\t"
				<< m[i].getType()
				<< endl;
			count += 1;
		}

	}

	else if (row.size() == 2) {

		if (isDigits(row[1])) {


			try {

				if (stoi(row[1]) < 1 || stoi(row[1]) > 10) {
					throw runtime_error("\nUnable to process command. The rating of: " + row[1] + " is invalid.");
				}

				else {

					//write headings to outFile
					outFile << "\n" << endl;
					outFile << setfill('+') << setw(50);
					outFile << "\n\tYOUR MEDIA LIST\n" << endl;

					outFile << "#" << "\tTITLE" << "\t\tYEAR" << "\tRATING" << "\tTYPE" << endl;

					//iterate through media vector and only print media with values greater than or equal to rating provided
					int count = 1;
					for (int i = 0; i < m.size(); i++) {
						if (m[i].getRating() >= stoi(row[1])) {
							outFile << count << "\t" << m[i].getTitle() << "\t"
								<< m[i].getYearReleased() << "\t"
								<< m[i].getRating() << "\t"
								<< m[i].getType()
								<< endl;
						}
						count += 1;
					}
				}
			}

			catch (runtime_error e) {
				outErr << e.what() << endl;
			}
		}

	}
}


void addNewMedia(ofstream& outFile, ofstream& outErr, vector<Media>& m, vector<string> row) {


	try {
		if (row[1] == "M") {
			
			if (!isDigits(row[4]) || !isDigits(row[6]) || !isDigits(row[7])) {
				throw runtime_error(
					"\nUnable to process command. There was an invalid value entered for item: "  + row[2]);
			}
			else if (stoi(row[4]) < 1 || stoi(row[4]) > 10) {
				throw runtime_error(
					"\nUnable to process command. There was an invalid value entered for rating: " + row[2]);
			}
			else if (stoi(row[7]) < 1500 || stoi(row[7]) > 2023) {
				throw runtime_error(
					"\nUnable to process command. There was an invalid value entered for year: " + row[2]);
			}

			Media movie('M', row[2], row[3], stoi(row[4]), row[5], stoi(row[6]), stoi(row[7]));
			m.push_back(movie);

			outFile << "\n" << row[2] << " was added to your list." << endl;

			//increase movie count
			Media::increaseCount(0);
		}

		else if (row[1] == "B") {

			if (!isDigits(row[4]) || !isDigits(row[6]) || !isDigits(row[7])) {
				throw runtime_error(
					"\nUnable to process command. There was an invalid value entered for item: " + row[2]);
			}
			else if (stoi(row[4]) < 1 || stoi(row[4]) > 10) {
				throw runtime_error(
					"\nUnable to process command. There was an invalid value entered for rating: " + row[2]);
			}
			else if (stoi(row[7]) < 1500 || stoi(row[7]) > 2023) {
				throw runtime_error(
					"\nUnable to process command. There was an invalid value entered for year: " + row[2]);
			}

			Media book('B', row[2], row[3], stoi(row[4]), row[5], stoi(row[6]), stoi(row[7]));
			m.push_back(book);

			outFile << "\n" << row[2] << " was added to your list." << endl;

			//increase book count
			Media::increaseCount(1);
		}

		else if (row[1] == "S") {

			if (!isDigits(row[4]) || !isDigits(row[6]) || !isDigits(row[7])) {
				throw runtime_error(
					"\nUnable to process command. There was an invalid value entered for item: " + row[2]);
			}
			else if (stoi(row[4]) < 1 || stoi(row[4]) > 10) {
				throw runtime_error(
					"\nUnable to process command. There was an invalid value entered for rating: " + row[2]);
			}
			else if (stoi(row[7]) < 1500 || stoi(row[7]) > 2023) {
				throw runtime_error(
					"\nUnable to process command. There was an invalid value entered for year: " + row[2]);
			}

			Media song('S', row[2], row[3], stoi(row[4]), row[5], stoi(row[6]), stoi(row[7]));
			m.push_back(song);

			outFile << "\n" << row[2] << " was added to your list." << endl;

			//increase song count
			Media::increaseCount(2);
		}
	}
	catch (runtime_error e) {
		outErr << e.what() << endl;
		outErr << "\n\n" << endl;
	}

	catch (...) {
		outErr << "unknown error found" << endl;
	}
}

void printTotals(ofstream& outFile) {

	//Media::printCounts(outFile);

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

}