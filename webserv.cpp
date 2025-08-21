#include "webserv.hpp"

#define BUFFER_SIZE 2096
int const port = 8282;

using namespace std;

void handleRequest(int clientFd, int serverFd){
	char buffer[BUFFER_SIZE] = {0};
	ifstream htmlPage("index.html");
	string fileContent; 

	if (htmlPage.is_open()){
		ostringstream buffer;
		buffer << htmlPage.rdbuf();
		fileContent = buffer.str();
		htmlPage.close();
	}
	else{
		cerr << "Error oppening index.html file\n";
		return ;
	}
	read(clientFd, buffer, BUFFER_SIZE);
	cout << "Received request:\n" << buffer << std::endl;
	string response_headers = "HTTP/1.1 200 OK\r\n";
	response_headers += "Content-Type: text/html\r\n";
	response_headers += "\r\n";
	send(clientFd, response_headers.c_str(), response_headers.length(), 0);
	send(clientFd, fileContent.c_str(), fileContent.length(), 0);
}

int main() {
	int clientSocket, serverSocket;
	struct sockaddr_in serverAddr, clientAddr;
	socklen_t clientAddrLen = sizeof(clientAddr);

	if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		cerr << "Error opening socket\n";
		return 1;
	}

	int opt = 1;
	setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_port = htons(port);
	serverAddr.sin_family = AF_INET;

	if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0){
		cerr << "Error binding connection\n";
		return 1;
	}

	if (listen(serverSocket, 10) < 0){
		cerr << "Error in listen\n";
	}

	cout << "Server listening on port: " << serverAddr.sin_port << endl;
	while (true){
		// clientAddr.sin_addr.s_addr = INADDR_ANY;
		// clientAddr.sin_family = AF_INET;
		// clientAddr.sin_port = htons(23072);
		cout << "Server socket: " << serverSocket 
			<< "\nClient Address: " << inet_ntoa(clientAddr.sin_addr) 
			<< "\nClient Port: " << ntohs(clientAddr.sin_port) << endl;
		if ((clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen)) < 0){
			cerr << "Error in accept\n";
			break;
		}
		handleRequest(clientSocket, serverSocket);
		close(clientSocket);
	}
	close(serverSocket);
	return (0);
}