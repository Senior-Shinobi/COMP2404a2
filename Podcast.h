
#ifndef PODCAST_H
#define PODCAST_H

#include <iostream>
#include <string>
#include "defs.h"
#include "Episode.h"


class Podcast {

	public:

		//constructors
		Podcast(const std::string& title,const std::string& host);
		Podcast(Podcast&);
		~Podcast();

		//getters
		std::string getTitle();
		std::string getHost();
		int getNumEpisodes();

		//other
		bool addEpisode(const std::string&,const std::string&);
		bool getEpisode(int,Episode**);
		bool lessThan(Podcast& pod);

		void print();

	private:
		std::string title,host;
		int numEps;
		Episode** arr;

};
#endif
