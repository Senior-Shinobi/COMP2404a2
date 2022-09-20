
#include "Podcast.h"


//arg constructor
Podcast::Podcast(const std::string& t,const std::string& h){
	title = t;
	host = h;
	arr = new Episode*[MAX_EPS];
	numEps = 0;
}
//deep copy constructor
Podcast::Podcast(Podcast& p){
	title = p.title;
	host = p.host;
	numEps = p.numEps;
	arr = new Episode*[MAX_EPS];
	Episode* e;
	for (int i = 0;i<numEps;i++){
		e = new Episode;
		*e = (*p.arr[i]);
		arr[i] = e;
	}
}
//destructor
Podcast::~Podcast(){

	for (int i = 0;i<numEps;i++){
		delete arr[i];
	}
	delete[] arr;
}

//getters
std::string Podcast::getTitle(){
	return title;
}
std::string Podcast::getHost(){
	return host;
}
int Podcast::getNumEpisodes(){
	return numEps;
}
//add to podcast array
bool Podcast::addEpisode(const std::string& t,const std::string& c){
	if (numEps == MAX_EPS){
		return false;
	}
	Episode* e = new Episode(title,numEps+1,t,c);
	arr[numEps] = e;
	numEps++;
	return true;
}
//getter for episode
bool Podcast::getEpisode(int index, Episode** ep){
	if (index >= numEps || index < 0){
		return false;
	}
	*ep = arr[index];
	return true;
}
//comparison for podcasts
bool Podcast::lessThan(Podcast& pod){
	if (title.compare(pod.title)<=0){
		return true;
	}
	return false;
}
//print function
void Podcast::print(){
	std::string ep ="Podcast: ";
	std::cout<<ep <<title<<std::endl
	<<host<<std::endl;
	for (int i = 0;i<numEps;i++){
		arr[i]->print();
	}
}
