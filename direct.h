#ifndef DIRECTMESSAGE_H
#define DIRECTMESSAGE_H

#include "content.h"
#include <string>
#include "time1.h"

class DirectMessage : public Content {
public:
    std::string message_ID;
    std::string to_who_ID;

    DirectMessage(std::string sender, Time time, std::string text, std::string picture, std::string video, std::string messageId, std::string toWhoId)
        : Content(sender, time, text, picture, video), message_ID(messageId), to_who_ID(toWhoId) {}
};

#endif // DIRECTMESSAGE_H
