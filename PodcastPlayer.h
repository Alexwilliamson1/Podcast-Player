#ifndef PODCASTPLAYER_H
#define PODCASTPLAYER_H

#include <iosfwd>

class Episode;

//A base \"PodcastPlayer\" class with a virtual \"play\" function:
class PodcastPlayer {
	public:
		virtual ~PodcastPlayer() = default;
		virtual void play(Episode& m, std::ostream& ost) const = 0;
};

//A derived \"AudioPlayer\" class with an overridden \"play\" function:
class AudioPlayer: public PodcastPlayer {
	public:
		void play(Episode& m, std::ostream& ost) const override;
};

//A derived \"VideoPlayer\" class with an overridden \"play\" function:
class VideoPlayer: public PodcastPlayer {
	public:
		void play(Episode& m, std::ostream& ost) const override;
};

#endif
			
			
