#ifndef TCPCLIENT_HPP
#define TCPCLIENT_HPP

#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
enum MessageType {
    BUFF,
    LOG,
    BINAREAY
};

struct Message {
    MessageType type;
    std::string content;
};

class TCPClient {
private:
    int clientSocket;

public:
    TCPClient(const char *serverIP, int serverPort);
    void sendMessage(const Message &message);
    void receiveMessage(Message &message);
    ~TCPClient();
};

#endif // TCPCLIENT_HPP
