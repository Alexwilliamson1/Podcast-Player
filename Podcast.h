#ifndef PODCAST_H
#define PODCAST_H

#include <iostream>
#include <string>
#include "Array.h"

class Episode;

//The public and private members of the Podcast class, including an array of episodes and functions for finding episodes and adding them to the array:
class Podcast {
	public:
		Podcast(const std::string& title, const std::string& host, const std::string& category);
		bool equals(const std::string& keyword) const;
		Episode* get(int index) const;
		int getSize() const;
		void print(std::ostream& ost) const;
		void printWithEpisodes(std::ostream& ost) const;
		void addEpisode(Episode*);
		friend std::ostream& operator<<(std::ostream& ost, const Podcast& podcast);
	private:
		Array<Episode*> episodes;
		std::string title, host, category;
};

#endif
