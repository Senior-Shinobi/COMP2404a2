
#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Podcast.h"
#include "PodArray.h"
#include "Subscriber.h"
#include "Episode.h"
#include "defs.h"

using namespace std;

class Network {

	public:
		//constructor
		Network(const std::string&);

		//destructor
		~Network();

		//getters
		bool getPodcast(const std::string& podcast,Podcast**);
		bool getSubscriber(const std::string& subscriber,Subscriber**);

		//other
		bool addPodcast(const std::string& podcast,const std::string& host);
		bool removePodcast(const std::string& podcast);
		bool addEpisode(const std::string& podcast,const std::string& title,const std::string& content);
		bool addSubscriber(const std::string& name,const std::string& creditcard);
		bool download(const std::string& subscriber,const std::string& podcast,Podcast**);
		bool stream(const std::string& subscriber,const std::string& podcast,int epNum,Episode** ep);
		bool hasSubscriber(const std::string& subscriber);
		void print();

	private:
		std::string name;
		PodArray* podArr;
		Subscriber* subArr[MAX_SUBS];
		int numSubs;

};
#endif
