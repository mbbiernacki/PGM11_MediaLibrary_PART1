#pragma once
/*

PSEUDOCODE

//MEDIA CLASS DONE -- SET UP 
MEDIA CLASS

	protected:
		char type;
		string title;
		string keyName;
		int rating;
		string genre;
		int length;
		int yearReleased;

	public:
		void Media();
		void Media(char type, string title, string keyName, int rating, string genre, int length, int yearRealeased);

		char getType();
		string getTitle();
		string getKeyName();
		int getRating();
		string getGenre();
		int getLength();
		int getYearReleased();

		void setType();
		void setTitle();
		void setKeyName();
		void setRating();
		void setGenre();
		void setLength();
		void setYearReleased();


use a vector<Media> to store all information from the library into a single vector



General Functions Needed:
	
	int readMediaList(istream &infile, ostream &outErr, vector<Media> &m)
	//PRE: files are open in main and acessible
	//POST: reads the data from the csv file, loads the objects into a vector<Media>
		produces an error report of any records that have errors

	void printAllMedia(istream &in, ostream& out, ostream& outErr, vector<Media>, &m);
	//PRE: media list is loaded with valid values, mediaCommands also loaded and verified
	//POST: writes all information to the report file


	void printMovieList();
	void printBookList();
	void printSongList();


	void printTotals(ostream& out);
	//PRE: static array initialized to 0
	//POST: prints the total count of movies, books, and songs in your library
	(HINT: use static class array, update as file is read and items are added to the vector)

	void addNewMedia(istream& inCommands, ostream& out, ostream& outErr, vector<Media>& m);
	//PRE: media list is loaded with valid values, first char in input stream has been read
	//POST: will read input string and separate all values into a vector<string> row; media record is pushed onto the vector and counts are updated


IN THE MAIN:
	//DONE
	OPEN mediaList.txt, mediaCommands.txt, outfile for report, outfile for errors
	
	//DONE
	LOAD media vector with objects
		CALL readMediaList(mediaFile, errorFile, mediaInfo)


	READ character FROM mediaCommands.txt to determine action
		M -> print movies in media list
		M, int -> print movies with a rating greater than or = to value

		B -> print books in media list
		B, int -> print books with a rating greater than or = to value

		A -> print all media in the list
		A, int -> print all media with a rating greater than or = to value provided

		S -> print songs in media list
		S, int -> print songs with rating greater than or = to value

		N, media type, title, name, rating, length, year -> add new media to the list

		Q -> quit/end input

	if char is not M B S A N or Q -> write to error file, continue

*/



/*


CODE GRAVEYARD


		/*if (inRec.length() == 1) {
			if (inRec != "M" && inRec != "B" && inRec != "A" && inRec != "S" && inRec != "Q") {
				errorFile << "The command: " << inRec << " is invalid." << endl;
			}
			else if (inRec == "M") {
				printMovieList(reportFile, errorFile, mediaInfo, row);
			}
			else if (inRec == "B") {
				//CALL PRINT BOOKS
			}
			else if (inRec == "A") {
				//CALL PRINT ALL MEDIA
			}
			else if (inRec == "S") {
				//CALL PRINT SONGS
			}
			else {
				break;
			}
		}*/



*/