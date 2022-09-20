
#include "Episode.h"


//arg constructor
Episode::Episode(const std::string& p,int num,const std::string& n,const std::string& c){
	name = n;
	podcast = p;
	number = num;
	content = c;
}
Episode::Episode(){
	name = "yes";
	podcast = "p";
	number = 1;
	content = "podcast";
}

//prints all room info
void Episode::play(){
	std::string ep ="Episode: ";
	std::cout<<ep <<podcast<<std::endl
	<<name<<std::endl
	<<number<<std::endl
	<<content<<std::endl;
}

void Episode::print(){
	play();
}
