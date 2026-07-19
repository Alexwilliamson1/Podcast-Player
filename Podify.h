#ifndef PODIFY_H
#define PODIFY_H

#include <string>
#include "Array.h"

class Podcast;
class Episode;

//A class for managing podcasts and creating arrays of episodes:
class Podify {
	public:
		void addPodcast(Podcast* podcast);
		void addEpisode(Episode* episode, const std::string& podcastTitle);
		const Array<Podcast*>& getPodcasts() const;
		Podcast* getPodcast(int index) const;
		Podcast* getPodcast(const std::string& title) const;
		void addToPlaylist(Array<Episode*>& episodes, Episode* episode) const;
		void getEpisodes(std::string& search, Array<Episode*>& searchMatches) const;
	private:
		Array<Podcast*> podcasts;

};

#endif
