
#ifndef EPISODE_H
#define EPISODE_H

#include <iostream>
#include <string>



class Episode {

	public:

		//constructors
		Episode(const std::string& podcast,int number,const std::string& name,const std::string& content);
		Episode();
		void play();
		void print();

	private:
		std::string name,content,podcast;
		int number;


};
#endif
