#include "Msg.hpp"
void Msg::setType(std::string Type)
{
    this->MsgType=Type;
}
void Msg::setDate(std::string Date)
{
    this->MsgDate=Date;
}
std::string Msg::getType()
{
    return this->MsgType;
}
std::string Msg::getDate()
{
    return this->MsgDate;
}