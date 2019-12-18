#ifndef __CIN_INTERFACE_H__
#define __CIN_INTERFACE_H__

#include <iostream>
#include <vector>
#include <string>
#include "jeekjeek.hpp"

using namespace std;

#define CMD_SIGNUP "signup"
#define CMD_LOGIN "login"
#define CMD_LOGOUT "logout"
#define CMD_JEEK "jeek"

#define SUB_CMD_PUBLISH "publish"
#define SUB_CMD_ABORT "abort"
#define SUB_CMD_TEXT "text"
#define SUB_CMD_MENTION "mention"
#define SUB_CMD_HASHTAG "tag"
#define CMD_SHOWJEEK "showJeek"
#define CMD_SEARCH "search"
#define CMD_COMMENT "comment"
#define CMD_REPLY "reply"
#define CMD_SHOWCOMMENT "showComment"
#define CMD_SHOWREPLY "showReply"
#define CMD_REJEEK "rejeek"
#define CMD_LIKE "like"
#define CMD_DISLIKE "dislike"
#define CMD_FOLLOW "follow"
#define CMD_UNFOLLOW "unfollow"
#define CMD_NOTIFICATIONS "notifications"


class Cin_interface{
public:
	void run(Jeekjeek& myjeekjeek);

};








#endif