
#include "Client.h"
//constructor
Client::Client(const std::string& n){
	name = n;
	podArr = new PodArray();
}

//destructor
Client::~Client(){
	delete podArr;
}
//adds podcast to local podarray
void Client::download(Network* n,const std::string& podcast){
	Podcast* p;
	if (n->download(name,podcast,&p)){
		Podcast* p2 = new Podcast(*p);
		if (podArr->addPodcast(p2)){
			std::string mes = "downloaded podcast";
			std::cout<<mes<<std::endl;
		} else {
			std::string error = "error downloading podcast";
			std::cout<<error<<std::endl;
		}
	} else {
		std::string error = "error downloading podcast";
		std::cout<<error<<std::endl;
	}
}
//plays given episode
void Client::stream(Network* n,const std::string& podcast,int epNum){
	Episode* ep;
	if (n->stream(name,podcast,epNum,&ep)){
		ep->play();
	}
}
//plays given episode from local podarray
void Client::playLocal(const std::string& podcast,int i){
	Podcast* p;
	Episode* e;
	if (podArr->getPodcast(podcast,&p)){
		if (p->getEpisode(i,&e)){
			e->play();
		} else {
			std::string error = "error finding episode";
			std::cout<<error<<std::endl;
		}
	} else {
		std::string error = "error finding podcast";
		std::cout<<error<<std::endl;
	}

}


void Client::print(){
	std::cout<<name<<std::endl;
	podArr->print();
}
