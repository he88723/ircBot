#include "ircSocket.h"

 IRCsocket::IRCsocket(){

    status   = -1;
    socketFd = -1;

}

void IRCsocket::init(std::string target){
    
    node                 = target.c_str();

    memset(&irc_host,0,sizeof(irc_host));

    irc_host.ai_family   = AF_UNSPEC;
    irc_host.ai_socktype = SOCK_STREAM;

    status = getaddrinfo(node,"6667",&irc_host,&irc_list);

    if(status != 0){

	std::cout << "There is some problem with getaddrinfo()!!" << std::endl;

    }

    socketFd = socket(irc_list->ai_family,irc_list->ai_socktype,irc_list->ai_protocol);

    if( socketFd == -1 ){

	std::cout << "There is some problem with socket()!!" << std::endl;

    }

}

void IRCsocket::connectServ(){

    status = connect(socketFd,irc_list->ai_addr,irc_list->ai_addrlen);

    if( status == -1 )
	std::cout << "There is some problem with connect()!!" << std::endl;

}

void IRCsocket::sendTo(std::string sendData){

    const char * data = sendData.c_str();
    send(socketFd,data,strlen(data),0);

}

std::string IRCsocket::receive(){
    
    char buffer[500];

    recv(socketFd, buffer, 500,0);
    std::string message(buffer);

    return message;

}

bool IRCsocket::isConnect(){

    status = -1;
    int size = sizeof(status);

    int error = getsockopt(socketFd,SOL_SOCKET,SO_ERROR,&status, (socklen_t*)&status);

    if((error != 0) || (status != 0))
	return false;

    return true;

}
