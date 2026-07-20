#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstddef>
#include "View.h"  
#include "Podcast.h"
#include "Episode.h"
#include "PodcastPlayer.h"

using namespace std;

//A constructor that initializes the \"PodcastPlayer\" object:
View::View(): player(&audioplayer) {}

//To output the main menu options and prompt the user for input:
void View::menu(vector<string>& menu, int& choice) {
  	cout << "Type the number of one of the options below:" << endl;
  	for (std::size_t i = 0; i < menu.size(); ++i){
    		cout << i + 1 <<".  "<< menu[i] << endl;
  	}
  	cout << "0.  End program" << endl << endl;

	cout << "Menu option: ";
	cin >> choice;
	cout << "\n";
	if (choice == 0)
		return;

	while (choice < 0 || choice > static_cast<int>(menu.size())) {
		cout << "Menu option: ";
	    	cin >> choice;
	    	cout << "\n";
  	}
}

//To output a list of the podcasts, including the title, host, and category of each:
void View::printAllPodcasts(const Array<Podcast*>& podcasts){
  	for (int i = 0; i < podcasts.getSize(); ++i){
    		cout << i + 1 << ".  " << *podcasts[i] << endl;
  	}
        cout << "\n";	
}

//To output the ASCII art and episodes for a given podcast:
void View::printPodcast(const Podcast* podcast, int podcastNumber) {
    	ifstream inputFile;
	if (podcastNumber == 1) {
    		inputFile.open("Videos/Podcast1.txt");
	} else if (podcastNumber == 2) {
    		inputFile.open("Videos/Podcast2.txt");
	} else if (podcastNumber == 3) {
		inputFile.open("Videos/Podcast3.txt");
	} else if (podcastNumber == 4) {
		inputFile.open("Videos/Podcast4.txt");
	}
    	if (!inputFile.is_open()) {
	    	cout << "There was a problem opening the .txt file." << endl;
    	}
	string line;
	while (getline(inputFile, line)) {
		cout << line << '\n';
	}
	cout << "\n";
	podcast -> printWithEpisodes(cout);
}

//To output the podcasts and prompt the user for input:
void View::podcastMenu(const Array<Podcast*>& podcasts, int& choice){
  	int numOptions = podcasts.getSize();
    	cout << "The podcasts are:" << endl;
	printAllPodcasts(podcasts);

	cout << "Type the number of a podcast to show its episodes or type 0 to return to the main menu." << endl;
	cout << endl;
	cout << "Podcast: ";
	cin >> choice;
	cout << "\n";
	if (choice == 0) {
		return;
	}

	while (choice < 0 || choice > numOptions) {
		cout << "Podcast: ";
	    	cin >> choice;
	    	cout << "\n";
	}
}

//To prompt the user to type the name of an episode:
void View::prompt(string& input){
	cout << "Type part or all of the name of an episode: ";
	char str[80];
	cin.clear();
	cin.getline(str, 80);
	cout << endl;
	input = str;
}

//To prompt the user to type the number of an episode:
void View::promptEpisode(int& choice, int& size){
	int numOptions = size;
	cout << "Episode: ";
	cin >> choice;
	if (choice == 0) {
		return;
	}
	while (choice < 0 || choice > numOptions) {
		cout << "Episode: ";
		cin >> choice;
	}
}

//To output the names of episodes in the playlist:
void View::printPlaylist(Array<Episode*>& episodes) {
	if (episodes.getSize() == 0) {
		cout << "Please add episodes to the playlist.\n\n";
		return;
	}
	cout << "The episodes in the playlist are:\n";
	for (int i = 0; i < episodes.getSize(); ++i) {
		cout << i + 1 << ".  " << *episodes[i] << "\n";
	}
	cout << "\n";
}

//To output the quotes or ASCII art for each episode in the playlist:
void View::playEpisodes(Array<Episode*>& episodes){
	if (episodes.getSize() == 0) {
		cout << "Please add episodes to the playlist.\n\n";
		return;
	}
	int playNext = -1;
	for (int i = 0; i < episodes.getSize(); ++i) {
		cout << i + 1 << ".  ";
		player -> play(*episodes[i], cout);
		while (playNext < 0 || playNext > 1 || i + 2 <= episodes.getSize()) {
			cout << "Type 1 to play the next episode in the playlist or 0 to return to the main menu: "; 
			cin >> playNext;
			cout << "\n";
			if (playNext == 0) {
				return;
			} else if (playNext == 1) {
				break;
			}
		}			
	}
}

//To prompt the user to choose the type of playback output:
void View::promptVideo(){
	int numOptions = 2;
	int choice = -1;
	cout << "1.  Audio player" << endl;
	cout << "2.  Video player" << endl << endl;

	while (true) {
		cout << "Player: ";
		cin >> choice;
		cout << "\n";
		if (choice > 0 || choice <= numOptions) {
			break;
		}
	}
	toggleVideo(choice == 2);
}

//To change the \"PodcastPlayer\" object:
void View::toggleVideo(bool video){
	if (video) {
		player = &videoplayer;
	} else {
		player = &audioplayer;
	}
}


