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
    printf("SEND MSG:%d\n%s\nsize:%lu\n",message.type,message.content.c_str(),sizeof(message));
}

void TCPClient::receiveMessage(Message &message)
{
    // Receive message type
    recv(clientSocket, &message.type, sizeof(message.type), 0);

    // Receive message content size
    int contentSize;
    recv(clientSocket, &contentSize, sizeof(contentSize), 0);

    // Receive message content
    char contentBuffer[contentSize + 1]; // +1 for null terminator
    recv(clientSocket, contentBuffer, contentSize, 0);
    contentBuffer[contentSize] = '\0'; // Null-terminate the received content

    message.content = contentBuffer;
    printf("RESV:\n");
    printf("MsgType:%d\nMsgDate:%s\n",message.type,message.content.c_str());
}

TCPClient::~TCPClient()
{
    close(clientSocket);
}


int main(int argc, char const *argv[])
{
    if(argc!=3)
    {
        printf("input Ip and Port!\n");
        return -1;
    }
    const char *ip=argv[1];
    int port=std::stoi(argv[2]);
    TCPClient client(ip,port); // Connect to server at IP  port 
    Message msg;
    msg.type = MessageType::REQUIRE_DATE;
    msg.content="REQUIRE_DATE";
    client.sendMessage(msg);
    Message recv;
    client.receiveMessage(recv);
    return 0;
}
