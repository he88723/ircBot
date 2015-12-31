#include "ircBot.h"

IRCbot::IRCbot(std::string nickName,std::string target){ 

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

void IRCbot::sendMes2C(std::string mes){

    basicIO.sendTo("PRIVMSG #" + channelName + " " + mes + "\n");

}

void IRCbot::pong(std::string recvData){

    if (recvData.find("PING") != std::string::npos)
	basicIO.sendTo("PONG irc.freenode.net\n");

}

std::string IRCbot::recveve(){

    return basicIO.receive();

}
