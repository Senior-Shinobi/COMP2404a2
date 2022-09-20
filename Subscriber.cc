
#include "Subscriber.h"


//arg constructor
Subscriber::Subscriber(const std::string& n,const std::string& c){
	name = n;
	creditcard = c;
}

//checks if Subscriber name is the same
bool Subscriber::matches(const std::string& n){
	if (n.compare(name) == 0){
		return true;
	}
	return false;
}

void Subscriber::print(){
	std::cout<<name<<std::endl<<creditcard<<std::endl;
}
