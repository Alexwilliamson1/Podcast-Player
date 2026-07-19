#include <iostream>
#include <fstream>
#include <limits>
#include <vector>
#include <string>

#include "Episode.h"
#include "Controller.h"
#include "View.h"
#include "Array.h"
#include "Podify.h"
#include "Podcast.h"
#include "PodcastFactory.h"

using namespace std;

//To create podcasts when \"initialize\" is set to true and prompt the user to input a menu option:
void Controller::launch(bool initialize) {
	if (initialize) {
    		initFromFile();		
    		cout << "Hello, welcome to Podcast Player.\n\n";

		ifstream inputFile;
    		inputFile.open("Videos/Title.txt");
    		if (!inputFile.is_open()) {
	    		cout << "There was a problem opening the file Title.txt." << endl;
    		}
		string line;
		while (getline(inputFile, line)) {
			cout << line << '\n';
		}
		cout << "\nNote: you may need to increase the width of your application window to properly display the text file images.\n\n";
	}
	int choice = -1;
	
	//showAllPodcasts();

	while (true){
		choice = -1;
		vector<string> menu = {
			"Show podcasts",
			"Search episodes",
			"Show playlist",
			"Play playlist",
			"Switch between audio and video playback"
		};
		view.menu(menu, choice);
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (choice == 0) break;
		switch (choice) {
			case 1: showPodcasts(); break;
			case 2: searchEpisodes(); break;
			case 3: showPlaylist(); break;
			case 4: playPlaylist(); break;
			case 5: toggleVideo(); break;
		} 
	}
	cout << "Thank you for using Podcast Player." << endl;
}

//To create podcasts of episodes from text files:
void Controller::initFromFile(){
        ifstream episodeFile;
    	episodeFile.open("media/media.txt");
    	if (!episodeFile.is_open()) {
	    	cout << "There was a problem opening the file media.txt." << endl;
    	}
    	string podcast, host, temp;
    	string title, content, category, video;
    	int numEpisodes = 0;

   	while (true) {
        	if(!getline(episodeFile, podcast)) break;
        	getline(episodeFile, host);
        	getline(episodeFile, temp);
        	numEpisodes = stoi(temp);
        	podify.addPodcast(factory.createPodcast(podcast, host, category));
        	for (int i = 0; i < numEpisodes; ++i) {
            		getline(episodeFile, title);
            		Episode* episode = factory.createEpisode(podcast, host, title);
            		if (episode == nullptr){
                		cout << "There was a problem creating the episode " << title << "." << endl;
                		continue;
            		}
            		podify.addEpisode(episode, podcast);
        	}    
    	}
    	episodeFile.close();
}

//To output a list of the podcasts:
void Controller::showAllPodcasts(){
    	cout << "The podcasts are:" << endl;
    	view.printAllPodcasts(podify.getPodcasts());
}

//To list podcasts and episodes and prompt the user to add episodes to the playlist:
void Controller::showPodcasts() {
	bool init = false;
    	int podcastChoice = -1;
    	view.podcastMenu(podify.getPodcasts(), podcastChoice);
	if (podcastChoice == 0) {	
		launch(init);
	}
    	Podcast* podcast = podify.getPodcast(podcastChoice - 1);
    	int size = podcast -> getSize();
	int numPrompts = size;
	int episodeChoice = -1;
	view.printPodcast(podcast, podcastChoice);
	cout << "Type the number of an episode to add it to the playlist or type 0 to return to the main menu." << endl;
	cout << endl;
    	while (numPrompts > 0) {
		view.promptEpisode(episodeChoice, size);
		if (episodeChoice == 0) {
			break;
		}
		Episode* episode = podcast -> get(episodeChoice - 1);
		podify.addToPlaylist(playlist, episode);
		numPrompts--;
		episodeChoice = -1;
        }
	cout << "\n";
}

//To find all episodes whose titles match the user's input and prompt the user to add found episodes to the playlist:
void Controller::searchEpisodes() {
	string searchWord;
        int input = -1;
	searchResults.clear();
        view.prompt(searchWord);
        podify.getEpisodes(searchWord, searchResults);
	if (searchResults.getSize() == 0) {
		std::cout << "There are no episode titles that contain \"" << searchWord << ".\"\n\n";
	} else {
		int size = searchResults.getSize();
		int numPrompts = size;
		cout << "The following episodes match your search:\n";
		for (int i = 0; i < searchResults.getSize(); i++) {
			cout << i + 1 << ".  " << searchResults[i] -> getEpisodeTitle() << "\n";
		}
		cout << "\n";
		cout << "Type the number of an episode to add it the playlist or 0 to return to the main menu.\n\n";
		while (numPrompts > 0) {
			cout << "Episode: ";
			cin >> input;
			while (input < 0 || input > searchResults.getSize()) {
				cout << "Episode: ";
				cin >> input;
			}
			if (input == 0) {
				return;
			}
        		podify.addToPlaylist(playlist, searchResults[input - 1]);
			numPrompts--;
			input = -1;
		}
		cout << "\n\n";
	}
} 

//To output a list of the episodes in the playlist:
void Controller::showPlaylist() {
    	cout << "Playlist size: " << playlist.getSize() << "\n\n";
    	view.printPlaylist(playlist);
} 

//To output the content of the episodes in the playlist:
void Controller::playPlaylist() {
    	view.playEpisodes(playlist);
}

//To prompt the user to choose the \"audio\" or \"video\" player for outputting podcast content:
void Controller::toggleVideo(){
    	view.promptVideo();
}
