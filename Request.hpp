#ifndef Request_HPP
#define Request_HPP

#include <iostream>

class Request {
	private:

	public:
		Request();
		Request(const Request& other);
		Request& operator=(const Request& other);
		~Request();
};

#endif