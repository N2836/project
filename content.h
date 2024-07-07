#ifndef CONTENT_H
#define CONTENT_H

#include "time1.h"
#include <string>

class Content {
public:
    std::string sender_ID;
    Time time_sent;
    std::string content_text;
    std::string content_picture;
    std::string content_video;

    Content(std::string sender, Time time, std::string text, std::string picture, std::string video)
        : sender_ID(sender), time_sent(time), content_text(text), content_picture(picture), content_video(video) {}
};

#endif // CONTENT_H
