#ifndef IRC_SOCKET_H
#define IRC_SOCKET_H

#include <iostream>
#include <cstring>
#include <string>
#include <sys/socket.h>
#include <netdb.h>

#endif

#define MAX_LENGTH 1024

class IRCsocket{

    public:

	IRCsocket();

	void init(std::string target);

        void connectServ();

	void sendTo(std::string sendData);

	std::string receive();

	bool isConnect();

    private:

	const char * node;
	int status,socketFd;
	struct addrinfo irc_host;
	struct addrinfo *irc_list;

};
