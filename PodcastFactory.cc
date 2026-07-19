#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <vector>

#include "PodcastFactory.h"
#include "Episode.h"
#include "Podcast.h"
#include "Search.h"
#include "PodcastPlayer.h"
#include "Podify.h"
#include "View.h"

template <typename T>
class Array;

//To create a podcast episode from a text file:
Episode* PodcastFactory::createEpisode(const std::string& pod, const std::string& host, const std::string& epTitle){

	//std::cout << epTitle << '\n';

        std::ifstream podFile("media/media2.txt");

        if (!podFile) {
	        std::cerr << "There was a problem opening media2.txt\n";
	        return nullptr;
        }

	//Creating variables for the data members of an \"Episode\" object:
        std::string episodeTitle;
        std::string content;
        std::string category;
        std::string videoFile;
        std::string line;

	//Reading \"media2.txt\" and assigning lines to variables: 
        while (getline(podFile, episodeTitle)) {
        	if (epTitle == episodeTitle){
                        if (!getline(podFile, category)) {
				break;
			}
			content = "";
			while (getline(podFile, line)) {
				if (line.size() >= 4 && (line.substr(line.size() - 4)) == ".txt") {
					videoFile = line;
					break;
				}
				content += line + "\n";

			}

                        return new Episode(pod, host, episodeTitle, category, content, "videos/" + videoFile);
                } else {
			getline(podFile, line);
			
		        
			while (getline(podFile, line)) {
				if (line.size() >= 4 && (line.substr(line.size() - 4)) == ".txt") {
					break;
				}
			}	
                }
        }
        std::cout << "Episode " << epTitle << " not found." << std::endl;

        return nullptr;
}

//Creating a \"Podcast\" object from strings representing the podcast title, host, and category: 
Podcast* PodcastFactory::createPodcast(const std::string& title, const std::string& host, const std::string& category) {
    return new Podcast(title, host, category);
}

//Creating a \"Search\" object from a string representing user input:
Search* PodcastFactory::search(const std::string& input){
    return new Search(input);
}

