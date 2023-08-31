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
#include <json/json.h>
#include <algorithm>
// #include "Msg.hpp"
#define Msg_INFO   "/home/lt/workspace/black-box/TCP/date/test.json"
#define Msg_NetStatus "/home/lt/workspace/black-box/profile/NetworkStatus.json"
enum MessageType {
    LOG,
    INFO,
    NetStatus,
    SYSSTATUE
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
    int getSock();
    void setSock(int socket);
    void sendMessage(int clientSocket, const Message &message);
    void receiveMessage(int clientSocket, Message &message);
    void closeClientSocket(int clientSocket);
    std::string ProcessMsgType(std::string msgType);
    std::string read_file_contents(const std::string &file_name);
    std::string ProcessRequest(std::string request);
    ~TCPServer();
};

#endif // TCPSERVER_HPP
