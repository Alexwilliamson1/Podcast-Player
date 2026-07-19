#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
#include <vector>
#include "Array.h"
#include "PodcastPlayer.h"

class Podcast;
class Episode;

//A \"View\" class for functions and objects that create the user interface:
class View {		
	public:
		View();
		void menu(std::vector<std::string>&, int& choice);
		void printAllPodcasts(const Array<Podcast*>& podcasts);
		void podcastMenu(const Array<Podcast*>& podcasts, int& choice);
		void printPodcast(const Podcast*, int podcastNumber);
        	void prompt(std::string& input);
		void promptEpisode(int& choice, int& size);
		void printPlaylist(Array<Episode*>&);
		void playEpisodes(Array<Episode*>&);
		void promptVideo();
		void toggleVideo(bool);
	private:
		AudioPlayer audioplayer;
		VideoPlayer videoplayer;
		PodcastPlayer* player;			
};

#endif
