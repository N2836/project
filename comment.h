#ifndef COMMENT_H
#define COMMENT_H

#include "content.h"
#include <string>
#include "time1.h"
#include<QTime>
class Comment : public Content {
public:

    std::string post_ID;
    std::string comment_ID;
    Comment(std::string sender, Time time, std::string text, std::string picture, std::string video, std::string postId, std::string commentId)
        : Content(sender, time, text, picture, video), post_ID(postId), comment_ID(commentId) {}
};

#endif // COMMENT_H
