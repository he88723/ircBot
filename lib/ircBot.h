#ifndef IRCBOT_H
#define IRCBOT_H

#include "ircSocket.h"

#endif

class IRCbot{

    public:

	IRCbot(std::string nickName,std::string target);
	void login();
	void joinChannel(std::string channel);
	void sendMes2C(std::string mes);
	void pong(std::string recvData);
	std::string recveve();

    private:
	
	IRCsocket basicIO;
	std::string nick;
	std::string channelName;
	std::string targetLink;

};
