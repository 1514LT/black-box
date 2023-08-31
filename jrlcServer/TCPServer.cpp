
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
        char ipBuffer[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(clientAddress.sin_addr), ipBuffer, INET_ADDRSTRLEN);
        int clientPort = ntohs(clientAddress.sin_port);

        std::cout << "Client connected from IP: " << ipBuffer << " Port: " << clientPort << std::endl;
        return;
    }
}

void TCPServer::sendMessage(int clientSocket, const Message &message)
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
    auto it = std::find(clientSockets.begin(), clientSockets.end(), clientSocket);
    if (it != clientSockets.end())
    {
        close(clientSocket);
        std::cout << "Client disconnected from socket: " << clientSocket << std::endl;
        clientSockets.erase(it);
    }
    else
    {
        std::cout << "Client socket not found in the list." << std::endl;
    }
}
std::vector<int> TCPServer::getSockets() const
{
    return clientSockets; // Return the vector of client sockets
}
TCPServer::~TCPServer()
{
    for (int clientSocket : clientSockets) {
        close(clientSocket);
    }
}
std::string TCPServer::read_file_contents(const std::string &file_name)
{
    std::ifstream file(file_name);
    if (!file.is_open()) {
        return "文件不存在";
    }

    std::string content((std::istreambuf_iterator<char>(file)),
                        (std::istreambuf_iterator<char>()));
    
    return content;
}
int TCPServer::getSock()
{
    return this->serverSocket;
}

void TCPServer::setSock(int socket)
{
    this->serverSocket=socket;
}

std::string JsonToString(const Json::Value& jsonObject) {
    Json::StreamWriterBuilder writer;
    std::string jsonString = Json::writeString(writer, jsonObject);
    return jsonString;
}

Json::Value StringToJson(const std::string& jsonString) {
    Json::CharReaderBuilder readerBuilder;
    Json::Value root;
    std::istringstream jsonStream(jsonString);
    std::string errors;

    bool parsingSuccessful = Json::parseFromStream(readerBuilder, jsonStream, &root, &errors);
    if (!parsingSuccessful) {
        return Json::Value();
    }

    return root;
}

std::string TCPServer::ProcessRequest(std::string request)
{
    std::string buf=read_file_contents(request);
    printf("read_buf:%s\n",buf.c_str());
    return buf;
}
std::string TCPServer::ProcessMsgType(std::string msgType)
{
    std::string msgTypes[]={"LOG","INFO","NetStatus","SYSSTATUE"};
    int arry_size=sizeof(msgTypes)/sizeof(msgTypes[0]);
    int index=0;
    size_t startPos=1;
    for(index=0;index<arry_size;index++)
    {
      if(msgType.find(msgTypes[index])!=std::string::npos)
      {
        startPos=0;
        break;
      }
    }
    if(startPos!=0)
    {
      std::cout << "msgType not found" << std::endl;
      return "msgType not found";
    }
    std::string buf="";
    switch (index)
    {
    case MessageType::LOG:
        break;
    case MessageType::INFO:
        buf=ProcessRequest(Msg_INFO);
        break;
    case MessageType::SYSSTATUE:
        break;
    case MessageType::NetStatus:
        buf=ProcessRequest(Msg_NetStatus);
        break;
    default:
        break;
    }
    return buf;
}
int main(int argc, char const *argv[])
{
    if(argc!=2)
    {
        printf("input Ip and Port!\n");
        return -1;
    }
    int port=std::stoi(argv[1]);
    TCPServer server(port); // Initialize server on port 12345
    while(1)
    {
        server.acceptConnections();
        
        std::vector<int> connectedSockets = server.getSockets();
        for (int socket : connectedSockets)
        {
            unsigned char buf[256] = "";
            void *p=buf;
            // std::string buf="";
            int connectFlage=recv(socket, p, sizeof(buf), 0);
            printf("------>buf:%s,size:%lu\n",buf,strlen((char*)p));
            if(connectFlage==0 || strlen((char*)p)<5)
            {
                if(strlen((char*)p)==2)
                {
                    printf("ping 测试链接到来\n");
                    sleep(5);
                }
                printf("客户端断开了\n");
                server.closeClientSocket(socket);
                continue;
            }
            std::string MSG_Date(reinterpret_cast<char*>(buf));
            Json::Value root;
            root=StringToJson(MSG_Date);
            std::string MSG_Type=root["MSG_Type"].asString();
            printf("MSG_Type:%s\n",MSG_Type.c_str());
            try
            {
                std::string date=server.ProcessMsgType(MSG_Type);
                send(socket,date.c_str(),strlen(date.c_str()),0);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            } 
        }
    }
    return 0;
}
