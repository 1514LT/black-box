#ifndef TCPSERVER_HPP
#define TCPSERVER_HPP
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <vector>
#include <string>
// #include "Msg.hpp"

enum MessageType {
    BUFF,
    LOG,
    BINAREAY
};


struct Message {
    MessageType type;
    std::string content;
};

class TCPServer {
private:
    int serverSocket;
    std::vector<int> clientSockets;
public:
    // Msg *msg;

public:
    TCPServer(int port);
    std::vector<int> getSockets() const;
    void acceptConnections();
    void sendMessage(int clientSocket, const Message &message);
    void receiveMessage(int clientSocket, Message &message);
    void closeClientSocket(int clientSocket);
    ~TCPServer();
};

#endif // TCPSERVER_HPP
