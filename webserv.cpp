#include "webserv.hpp"

typedef struct server{
	int socket;
}	server;

int main(){
	server *webServ = new server;
	webServ->socket = socket();
	delete webServ;
}