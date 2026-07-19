CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

OBJECTS = \
	Main.o \
	View.o \
	Controller.o \
	Podify.o \
	Podcast.o \
	Episode.o \
	PodcastPlayer.o \
	PodcastFactory.o \

all: PodcastPlayer

PodcastPlayer: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f PodcastPlayer *.o

.PHONY: all clean