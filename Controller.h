#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "View.h"
#include "Array.h"
#include "Podify.h"
#include "Episode.h"
#include "PodcastFactory.h"

//A class for controlling the user interface, including main menu functionality; podcast and episode creation; the playlist; and search results:
class Controller {
	public:		
		void launch(bool initialize);	
	private:
		void initFromFile();
		void showAllPodcasts();
		void showPodcasts();
		void searchEpisodes(); 
		void showPlaylist(); 
		void playPlaylist(); 
		void toggleVideo(); 
		
		View view;
		Podify podify;
		PodcastFactory factory;
		Array<Episode*> playlist;
		Array<Episode*> searchResults;
};

#endif
