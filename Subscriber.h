
#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <iostream>
#include <string>



class Subscriber {

	public:

		//constructors
		Subscriber(const std::string& name,const std::string& creditcard);
		bool matches(const std::string& name);
		void print();

	private:
		std::string name,creditcard;


};
#endif
