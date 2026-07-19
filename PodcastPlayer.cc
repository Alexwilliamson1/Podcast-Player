#include <iostream>
#include <fstream>
#include <cstdlib>
#include "PodcastPlayer.h"
#include "Episode.h"

//To output quotes from a given podcast episode:
void AudioPlayer::play(Episode& m, std::ostream& ost) const {
	ost << m << ":\n\n" << m.getAudio() << "\n";
}

//To output the ASCII art for a given podcast episode:
void VideoPlayer::play(Episode& m, std::ostream& ost) const {
	ost << m << ":\n\n";
	
	std::ifstream inputFile(m.getVideoFile());
	if (!inputFile) {
		std::cerr << "There was a problem opening " << m.getVideoFile() << "." << std::endl;
		std::exit(1);
	}
	std::string line;
	//Reading and outputting lines from a text file:
	while (std::getline(inputFile, line)) {
		ost << line << '\n';
	}
	ost << "\n";
}

