#ifndef PODCASTFACTORY_H
#define PODCASTFACTORY_H

#include <string>

class Episode;
class Podcast;
class Search;

//A class for creating Podcast, Episode, and Search objects:
class PodcastFactory {	
	public:
		Episode* createEpisode(const std::string& pod, 
				       const std::string& host, 
				       const std::string& title);
		Podcast* createPodcast(const std::string& title, 
				       const std::string& host,
				       const std::string& category);
		Search* search(const std::string& input);
};

#endif
