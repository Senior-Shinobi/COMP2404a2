
#include "Network.h"
//constructor
Network::Network(const std::string& n){
	numSubs = 0;
	name = n;
	podArr = new PodArray();
}

//destructor
Network::~Network(){
	for (int i = 0; i < numSubs; ++i){
		delete subArr[i];
	}
	delete podArr;
}
//getter functions
bool Network::getPodcast(const std::string& podcast, Podcast** pod){
	return podArr->getPodcast(podcast,pod);
}
bool Network::getSubscriber(const std::string& name, Subscriber** sub){
	for (int i = 0; i<numSubs;i++){
    if (subArr[i]->matches(name)){
      *sub = subArr[i];
      return true;
    }
  }
  return false;
}

//other functions
bool Network::addPodcast(const std::string& podcast,const std::string& host){
	if (podArr->isFull()){
		return false;
	}
	Podcast* p = new Podcast(podcast,host);
	return podArr->addPodcast(p);
}

bool Network::removePodcast(const std::string& podcast){
	Podcast* pod;
	if (podArr->removePodcast(podcast,&pod)){
		delete pod;
		return true;
	}
	return false;
}

bool Network::addEpisode(const std::string& podcast,const std::string& title,const std::string& content){
	Podcast* pod;
	if (podArr->getPodcast(podcast,&pod)){
		return pod->addEpisode(title,content);
	}
	return false;
}

bool Network::addSubscriber(const std::string& name,const std::string& creditcard){
	if (numSubs >= MAX_SUBS) return false;
	Subscriber* s = new Subscriber(name,creditcard);
	subArr[numSubs] = s;
	numSubs++;
	return true;
}

bool Network::download(const std::string& subscriber,const std::string& podcast,Podcast** pod){

	if (hasSubscriber(subscriber)){
		if (podArr->getPodcast(podcast,pod)){
			return true;
		}else{
			std::string error = "No podcast with given name exists";
			std::cout<< error<<std::endl;
			return false;
		}
	} else{
		std::string error = "No subscriber with given name exists";
		std::cout<< error<<std::endl;
		return false;
	}
}

bool Network::stream(const std::string& subscriber,const std::string& podcast,int epNum,Episode** ep){
	Podcast* pod;
	if (hasSubscriber(subscriber)){
		if (podArr->getPodcast(podcast,&pod)){
			return pod->getEpisode(epNum,ep);
		}else{
			std::string error = "No podcast with given name exists";
			std::cout<< error<<std::endl;
			return false;
		}
	} else{
		std::string error = "No subscriber with given name exists";
		std::cout<< error<<std::endl;
		return false;
	}
}

bool Network::hasSubscriber(const std::string& subscriber){
	for (int i = 0;i<numSubs;i++){
		if (subArr[i]->matches(subscriber)){
			return true;
		}
	}
	return false;
}

void Network::print(){
	std::cout<<name<<std::endl;
	podArr->print();
	for (int i = 0;i<numSubs;i++){
		subArr[i]->print();
	}
}
