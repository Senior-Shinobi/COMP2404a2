
#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Podcast.h"
#include "PodArray.h"
#include "Network.h"
#include "Episode.h"
#include "defs.h"

using namespace std;

class Client {

	public:
		//constructor
		Client(const std::string&);

		//destructor
		~Client();

		//other
		void download(Network*,const std::string&);
		void stream(Network*,const std::string&,int);
		void playLocal(const std::string&,int);
		void print();

	private:
		std::string name;
		PodArray* podArr;


};
#endif
