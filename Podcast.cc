#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Podcast.h"
#include "Episode.h"

//Overloading the stream insertion operator for \"Podcast\" objects:
std::ostream& operator<<(std::ostream& ost, const Podcast& podcast) {
	podcast.print(ost);
    	return ost;
}

//The constructor for \"Podcast\" objects:
Podcast::Podcast(const std::string& title, const std::string& host, const std::string& category) : title(title), host(host), category(category){}

//To check if the input string is the same as the podcast's title:
bool Podcast::equals(const std::string& keyword) const {
	return title == keyword;
}

//To return the episode at the given index:
Episode* Podcast::get(int index) const{
	if (index < 0 || index >= episodes.getSize()) {
		std::cerr << "Please use a valid array index." << std::endl;
		std::exit(1);
	}
	return episodes[index];
}

//To return the number of episodes in a podcast:
int Podcast::getSize() const {
	return episodes.getSize();
}

//To output a podcast's title, host, and category:
void Podcast::print(std::ostream& ost) const {
	if (episodes.getSize() == 0) {
		ost << "The host is " << host 
	    		<< ", the title is " << title 
	    		<< ", and there are no episodes."; 
		return;	
	}	
	const std::string& category = episodes[0] -> getCategory();
	ost << title << ", " << "hosted by " << host << ".  " 
		<< "Category: " << category << ".";
}

//To output a podcast's episodes:
void Podcast::printWithEpisodes(std::ostream& ost) const {
	if (episodes.getSize() == 0) {
		ost << "The podcast " << title << " has no episodes.\n";
		return;
	}
	ost << "The episodes for " << title << " are:\n";
	for (int i = 0; i < episodes.getSize(); ++i) {
		ost << i + 1 << ".  " << *(episodes[i]) << std::endl;
	}
	ost << "\n";
}

//To add an episode to a podcast:
void Podcast::addEpisode(Episode* episode) {
	episodes += episode;
}
