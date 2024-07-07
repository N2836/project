#ifndef POST_H
#define POST_H

#include "content.h"
#include "like.h"
#include "comment.h"
#include <vector>
#include <string>

class Post : public Content {
public:
    std::string post_ID;
    int repost_counter;
    std::vector<Like> likes;
    std::vector<Comment> comments;

    Post(std::string sender, Time time, std::string text, std::string picture, std::string video, std::string postId)
        : Content(sender, time, text, picture, video), post_ID(postId), repost_counter(0) {}

    void addLike(Like like) {
        likes.push_back(like);
    }

    void addComment(Comment comment) {
        comments.push_back(comment);
    }
};

#endif // POST_H

