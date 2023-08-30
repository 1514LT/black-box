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
#include <fstream>
// #include "Msg.hpp"
#define JSON1   "/home/lt/workspace/black-box/TCP/date/test.json"
enum MessageType {
    BUFF,
    LOG,
    BINAREAY,
    REQUIRE_DATE,
    JSON_DATE,
    END
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
    std::string read_file_contents(const std::string &file_name);
    ~TCPServer();
};

#endif // TCPSERVER_HPP
