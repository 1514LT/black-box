#include "TCPClient.hpp"


TCPClient::TCPClient(const char *serverIP, int serverPort)
{
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(serverPort);
    if (inet_pton(AF_INET, serverIP, &serverAddress.sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    if (connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }
}

void TCPClient::sendMessage(const Message &message)
{
    // Send message type
    send(clientSocket, &message.type, sizeof(message.type), 0);

    // Send message content size
    int contentSize = message.content.size();
    send(clientSocket, &contentSize, sizeof(contentSize), 0);

    // Send message content
    send(clientSocket, message.content.c_str(), contentSize, 0);
    printf("SEND MSG:%d,%s,size:%lu\n",message.type,message.content.c_str(),sizeof(message));
}

void TCPClient::receiveMessage(Message &message)
{
    recv(clientSocket, &message, sizeof(message), 0);
}

TCPClient::~TCPClient()
{
    close(clientSocket);
}


int main()
{
    TCPClient client("192.168.2.82", 8000); // Connect to server at IP 127.0.0.1, port 12345
    Message msg;
    msg.type = MessageType::LOG;
    msg.content="HELLO";
    client.sendMessage(msg);
    return 0;
}