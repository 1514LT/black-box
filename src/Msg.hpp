#ifndef MSG_HPP
#define MSG_HPP
#include <stdio.h>
#include <string.h>
#include <iostream>
class Msg
{
private:
    /* data */
    std::string MsgType;
    std::string MsgDate;
public:
    Msg(/* args */);
    Msg(std::string Type,std::string Date);
    ~Msg();
    void setType(std::string Date);
    void setDate(std::string Type);
    std::string getType();
    std::string getDate();
};

Msg::Msg(/* args */)
{
    this->MsgType="";
    this->MsgDate="";
}
Msg::Msg(std::string Type,std::string Date)
{
    this->MsgType=Type;
    this->MsgDate=Date;
}
Msg::~Msg()
{
}


#endif