
#include "PodArray.h"

PodArray::PodArray(){
	numPods = 0;
	podcasts = new Podcast*[MAX_PODS];
}

PodArray::PodArray(PodArray& pa){
	podcasts = new Podcast*[MAX_PODS];
	for (int i =0 ; i < pa.numPods; ++i){
		podcasts[i] = new Podcast(*pa.podcasts[i]);
	}
	numPods = pa.numPods;

}


PodArray::~PodArray(){
	for (int i = 0; i < numPods; ++i){
		delete podcasts[i];
	}
	delete [] podcasts;
}

bool PodArray::addPodcast(Podcast* p){
	if (numPods >= MAX_PODS) return false;
	for (int i = numPods; i > 0; --i){
		if (p->lessThan(*podcasts[i-1])){
			podcasts[i] = podcasts[i-1];
		}else{
			podcasts[i] = p;
			++numPods;
			return true;
		}
	}
	podcasts[0] = p;
	++numPods;
	return true;
}

bool PodArray::removePodcast(const std::string& title, Podcast** pod){

	for (int i = 0;i<numPods;i++){
		if ((podcasts[i]->getTitle()).compare(title) == 0){
			*pod = podcasts[i];
			for (int j = i;j<numPods;j++){
				podcasts[j] = podcasts[j+1];
			}

			numPods--;
			return true;
		}
	}


	return false;
}

bool PodArray::getPodcast(const std::string& title, Podcast** pod){
	for (int i = 0; i<numPods;i++){
    if ((podcasts[i]->getTitle()).compare(title) == 0){
      *pod = podcasts[i];
      return true;
    }
  }
  return false;
}

bool PodArray::isFull(){
	return numPods >= MAX_PODS;
}

int PodArray::size(){
	return numPods;
}

void PodArray::print(){
	std::cout<<numPods<<std::endl;
	for (int i = 0; i < numPods; ++i){
		podcasts[i]->print();
	}
}
