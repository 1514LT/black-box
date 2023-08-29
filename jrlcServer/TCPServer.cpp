
#include "TCPServer.hpp"

TCPServer::TCPServer(int port)
{
    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Bind socket
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(serverSocket, 5) == -1) {
        perror("Error listening");
        exit(EXIT_FAILURE);
    }
}

void TCPServer::acceptConnections()
{
    while (true)
    {
        sockaddr_in clientAddress;
        socklen_t clientSize = sizeof(clientAddress);
        int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientSize);
        if (clientSocket == -1)
        {
            perror("Error accepting connection");
            continue;
        }
        clientSockets.push_back(clientSocket);
        std::cout << "Client connected" << std::endl;
        return;
    }
}

void TCPServer::sendMessage(int clientSocket, const Message &message)
{
    send(clientSocket, &message, sizeof(message), 0);
}

void TCPServer::receiveMessage(int clientSocket, Message &message)
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

void TCPServer::closeClientSocket(int clientSocket)
{
    close(clientSocket);
    std::cout << "Client disconnected" << std::endl;
}
std::vector<int> TCPServer::getSockets() const
{
    return clientSockets; // Return the vector of client sockets
}
TCPServer::~TCPServer()
{
    close(serverSocket);
    for (int clientSocket : clientSockets) {
        close(clientSocket);
    }
}


int main()
{
    TCPServer server(8000); // Initialize server on port 12345
    
    server.acceptConnections();
    
    std::vector<int> connectedSockets = server.getSockets();
    for (int socket : connectedSockets)
    {
    Message msg;
    server.receiveMessage(socket,msg);
    }
    return 0;
}
