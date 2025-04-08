#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <iomanip>
#include <time.h>

using namespace std;
int main() {

	vector<string> songName;
	string song;
	vector<string> artistName;
	string artist;
	vector<string> songYear;
	string year;

	string nameTemp;
	string artistTemp;
	string yearTemp;

	int index1;
	int index2;

	char selection = 0;
	char listSelection = 0;
	char gameSelection = 0;
	char songSelect = 0;
	int numSongs = 0;
	ifstream dataFile;

	dataFile.open ("songInfo.txt");

	if (dataFile.is_open()) {
	}
	else {
		cout << "File was not opened" << endl;
		return 0;
	}

	while (dataFile) {
		getline(dataFile, song);
		getline(dataFile, artist);
		getline(dataFile, year);

		songName.push_back(song);
		artistName.push_back(artist);
		songYear.push_back(year);

		numSongs++;
	}

	numSongs--;

	dataFile.close();

	srand(time(NULL));

	cout << "Welcome to my ETHN 1200 final project" << endl;

	while (selection != 'x') {
		cout << "\nPress 's' and then enter if you want to see the full list of songs" << endl;
		cout << "Press 'g' and then enter if you want to play the guessing game" << endl;
		cout << "Press 'x' and then enter to quit" << endl;
		cout << "Your selection: ";
		std::cin >> selection;

		switch (selection) {
		case 's':

			while (listSelection != 'x') {
				cout << "\nChoose how you would like to view the list:" << endl;
				cout << "Press 't' and then enter to see the list sorted by song title" << endl;
				cout << "Press 'a' and then enter to see the list sorted by artist" << endl;
				cout << "Press 'y' and then enter to see the list sorted by year" << endl;
				cout << "Press 'x' and then enter if you want to go back" << endl;
				cout << "Your selection: ";
				std::cin >> listSelection;

				switch (listSelection) {
				case 't':

					cout << "\nSong list sorted by title:" << endl;

					for (int i = 0; i < numSongs; i++) {
						for (int j = 0; j < numSongs; j++) {
							if (songName[i] < songName[j]) {

								nameTemp = songName[i];
								songName[i] = songName[j];
								songName[j] = nameTemp;

								artistTemp = artistName[i];
								artistName[i] = artistName[j];
								artistName[j] = artistTemp;

								yearTemp = songYear[i];
								songYear[i] = songYear[j];
								songYear[j] = yearTemp;
							}
						}
					}

					cout << endl;
					cout << setw(48) << left << "Song Title" << setw(40) << left << "Artist" << setw(4) << "Year" << endl;
					cout << setw(100) << setfill('_') << "_" << endl;
					cout << endl;
					for (int i = 0; i < numSongs; i++) {
						cout << setfill('-') << setw(48) << left << songName[i] << setw(40) << left << artistName[i] << setw(4) << songYear[i] << endl;
					}
					cout << endl;

					break;

				case 'a':
					cout << "\nSong list sorted by artist:" << endl;

					for (int i = 0; i < numSongs; i++) {
						for (int j = 0; j < numSongs; j++) {
							if (artistName[i] < artistName[j]) {

								nameTemp = songName[i];
								songName[i] = songName[j];
								songName[j] = nameTemp;

								artistTemp = artistName[i];
								artistName[i] = artistName[j];
								artistName[j] = artistTemp;

								yearTemp = songYear[i];
								songYear[i] = songYear[j];
								songYear[j] = yearTemp;
							}
						}
					}

					cout << endl;
					cout << setw(48) << left << "Song Title" << setw(40) << left << "Artist" << setw(4) << "Year" << endl;
					cout << setw(100) << setfill('_') << "_" << endl;
					cout << endl;
					for (int i = 0; i < numSongs; i++) {
						cout << setfill('-') << setw(48) << left << songName[i] << setw(40) << left << artistName[i] << setw(4) << songYear[i] << endl;
					}
					cout << endl;

					break;

				case 'y':
					cout << "\nSong list sorted by year:" << endl;

					for (int i = 0; i < numSongs; i++) {
						for (int j = 0; j < numSongs; j++) {
							if (songYear[i] < songYear[j]) {

								nameTemp = songName[i];
								songName[i] = songName[j];
								songName[j] = nameTemp;

								artistTemp = artistName[i];
								artistName[i] = artistName[j];
								artistName[j] = artistTemp;

								yearTemp = songYear[i];
								songYear[i] = songYear[j];
								songYear[j] = yearTemp;
							}
						}
					}

					cout << endl;
					cout << setw(48) << left << "Song Title" << setw(40) << left << "Artist" << setw(4) << "Year" << endl;
					cout << setw(100) << setfill('_') << "_" << endl;
					cout << endl;
					for (int i = 0; i < numSongs; i++) {
						cout << setfill('-') << setw(48) << left << songName[i] << setw(40) << left << artistName[i] << setw(4) << songYear[i] << endl;
					}
					cout << endl;

					break;

				case 'x':
					cout << "\nReturning to selection" << endl;
					break;

				default:
					cout << "\nPlease input one of the options:\n" << endl;
				}
			}
			break;

		case 'g':
			cout << "\nYou will be given two song options and have to guess which song is newer" << endl;

			while (gameSelection != 'x') {
				index1 = rand() % numSongs;
				index2 = rand() % numSongs;
				
				while (songYear[index1] == songYear[index2]) {
					index2 = rand() % numSongs;
				}

				cout << endl;
				cout << "Song 1:" << endl;
				cout << "'" << songName[index1] << "' by " << artistName[index1] << endl;
				cout << "\nSong 2:" << endl;
				cout << "'" << songName[index2] << "' by " << artistName[index2] << endl;
				cout << endl;

				cout << "Make your selection by pressing '1' for Song 1 or '2' for Song 2 and then enter: ";
				std::cin >> songSelect;
				
				while ((songSelect != '1') && (songSelect != '2')) {
					cout << "Please press '1' or '2' to and then enter to make your selection: ";
					std::cin >> songSelect;
				}

				if (songYear[index1] > songYear[index2]) {
					if (songSelect == '1') {
						cout << "\nCorrect! Song 1 came out in " << songYear[index1] << " and Song 2 came out in " << songYear[index2] << endl;
					}
					if (songSelect == '2') {
						cout << "\nSorry, that's incorrect. Song 1 came out in " << songYear[index1] << " and Song 2 came out in " << songYear[index2] << endl;
					}
				}

				if (songYear[index2] > songYear[index1]) {
					if (songSelect == '2') {
						cout << "\nCorrect! Song 1 came out in " << songYear[index1] << " and Song 2 came out in " << songYear[index2] << endl;
					}
					if (songSelect == '1') {
						cout << "\nSorry, that's incorrect. Song 1 came out in " << songYear[index1] << " and Song 2 came out in " << songYear[index2] << endl;
					}
				}

				cout << "\nPress 'x' to quit, or press any other letter to play again: ";
				std::cin >> gameSelection;
			}

			break;

		case 'x':
			cout << "\nExiting program\n" << endl;
			return 0;
			break;

		default:
			cout << "\nInput not recognized, please press one of the options to continue:\n" << endl;
		}
	}

	return 0;
}