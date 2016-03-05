#ifndef IRCBOT_H
#define IRCBOT_H

#include <iostream>
#include <cstring>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

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
		const char *node;
		int status,socketFd;
		struct addrinfo irc_host;
		struct addrinfo *irc_list;

}

class IRCbot{

    public:

	IRCbot(std::string nickName,std::string target);
	void login();
	void joinChannel(std::string channel);
	std::string pong(std::string recvData);

	void sendMes2C(std::string mes, std::string channelSend){
	basicIO.sendTo("PRIVMSG #" + channelSend + " " + mes + "\n");
	}

	bool isConnected(){
	return basicIO.isConnected();
	}

	std::string recveve(){
	return pong(basicIO.receive());
	}

    private:
	
	IRCsocket basicIO;
	std::string nick;
	std::string channelName;
	std::string targetLink;

};

//////////////////////////////////////////////IRCsocket

IRCsocket::IRCsocket(){

	status   = -1;
	socketFd = -1;

}

void IRCsocket::init(std::string target){

	node                 = target.c_str();
	memset(&irc_host, 0, sizeof(irc_host));

	irc_host.ai_family   = AF_UNSPEC;
	irc_host.ai_socktype = SOCK_STREAM;

	status   = getaddrinfo(node,"6667",&irc_host,&irc_list);
	if(status != 0)
		std::cout << "IRC_SERVER ERROR!!!!!!!" << std::endl;

	socketFd = socket(irc_list->ai_family,irc_list->ai_socktype,irc_list->ai_protocol);

	if(socketFd == -1)
		std::cout << "SOCKET ERROR!!!!!!!" << std::endl;

}

void IRCsocket::connectServ(){

	status = connect(socketFd,irc_list->ai_addr,irc_list->ai_addrlen);

	if(status == -1)
		std::cout << "CONNECT ERROR!!!!!!!" <<endl;

}

void IRCsocket::sendTo(std::string sendData){

	const char *data = sendData.c_str();
	send(socketFd,data,strlen(data),0);

}

std::string IRCsocket::receive(){

	char buffer[MAX_LENGTH];

	recv(socketFd,buffer,MAX_LENGTH,0);
	std::string message(buffer);

	return message;

}

bool IRCsocket::isConnect(){

	status = -1;

	int error = getsockopt(socketFd,SOL_SOCKET,SO_ERROR,&status,(socklen_t *)&status);

	if( (error != 0) || (status != 0) )
		return false;

	return true;
}

//////////////////////////////////////////////////////IRCbot

IRCbot::IRCbot(std::string nickName, std::string target){

	nick       = nickName;
	basicIO.init(target);
	targetLink = target;

}

void IRCbot::login(){

	basicIO.connectServ();
	basicIO.sendTo("NICK " + nick + "\n");
	basicIO.sendTo("USER " + nick + " 8 * :Cpp IRC Client\n");

}

void IRCbot::joinChannel(std::string channel){

	basicIO.sendTo("JOIN #" + channel + "\n");
	channelName = channel;

}

std::string IRCbot::pong(std::string recvData){

	if(recvData.find("PING") != std::string::npos)
		basicIO.sendTo("PONG " + targetLink + "\n");
	return recvData;

}

#endif
