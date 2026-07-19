#include <cstdlib>
#include <iostream>
#include "Podify.h"
#include "Podcast.h"
#include "Episode.h"

//To add a podcast to the playlist:
void Podify::addPodcast(Podcast* podcast) {
	podcasts += podcast;
}

//To add a given episode to a podcast:
void Podify::addEpisode(Episode* episode, const std::string& podcastTitle) {
	getPodcast(podcastTitle) -> addEpisode(episode);
}

//To return all podcasts:
const Array<Podcast*>& Podify::getPodcasts() const{
	return podcasts;
}

//To return the podcast at a given index:
Podcast* Podify::getPodcast(int index) const{
	return podcasts[index];
}

//To return the podcast with the given title, if it exists:
Podcast* Podify::getPodcast(const std::string& keyword) const{
	for (int i = 0; i < podcasts.getSize(); ++i) {
		if (podcasts[i] -> equals(keyword)) {
			return podcasts[i];
		}
	}
	std::cerr << "There is no podcast with the title " << keyword << "." << std::endl;
	std::exit(1);
}

//To add the given episode to the playlist:
void Podify::addToPlaylist(Array<Episode*>& episodes, Episode* episode) const {
	episodes += episode;
}

//To add all episodes whose titles contain the \"Search\" object string to the \"searchMatches\" array: 
void Podify::getEpisodes(std::string& search, Array<Episode*>& searchMatches) const {
	for (int i = 0; i < podcasts.getSize(); ++i) {
		Podcast* podcast = podcasts[i];
		for (int j = 0; j < podcast -> getSize(); ++j) {
			Episode* episode = podcast -> get(j);
			std::string epTitle = episode -> getEpisodeTitle();
			if (epTitle.find(search) != std::string::npos) {
				searchMatches += episode;	
			}
		}
	}
}


		
		
		
