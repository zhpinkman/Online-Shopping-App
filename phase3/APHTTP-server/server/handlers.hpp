#ifndef __HANDLERS__
#define __HANDLERS__
#include "../utils/include.hpp"
#include "../utils/request.hpp"
#include "../utils/response.hpp"
#include "route.hpp"
#include <exception>
#include <string>
#include <vector>
#include "server.hpp"
#include "../utils/utilities.hpp"
#include <algorithm>
#include <dirent.h>
#include <fstream>
#include <iostream>
#include <limits.h>
#include <map>
#include <netinet/in.h>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "jeekjeek/jeekjeek.hpp"
#include "jeekjeek/user_session.hpp"

#define SUCCESS "OK"
#define SEARCH_TYPE_POSTS "posts"
#define SEARCH_TYPE_USERS "users"
#define SEARCH_TYPE_HASHTAGS "hashtags"
#define ILLEGAL_CHARS "\\/\"<>|"

using namespace std;


class LoginHandler : public RequestHandler {
private:
  Jeekjeek* jeekjeek;
  User_sessions* sessions;
public:
  Response *callback(Request *req);
  LoginHandler(Jeekjeek* _jeekjeek, User_sessions* _sessions){
    jeekjeek = _jeekjeek;
    sessions = _sessions;
  }
};

class SignupHandler : public RequestHandler {
private:
  Jeekjeek* jeekjeek;
public:
  Response *callback(Request *req);

  SignupHandler(Jeekjeek* _jeekjeek){
    jeekjeek = _jeekjeek;
  }
};

class SearchHandler : public RequestHandler {
private:
  Jeekjeek* jeekjeek;
  User_sessions* sessions;
public:
  Response *callback(Request *req);
  SearchHandler(Jeekjeek* _jeekjeek, User_sessions* _sessions){
    jeekjeek = _jeekjeek;
    sessions = _sessions;
  }
};

class GetUsernameHandler : public RequestHandler {
private:
  User_sessions* sessions;
public:
  Response *callback(Request *req);
  GetUsernameHandler(User_sessions* _sessions){
    sessions = _sessions;
  }
};

class LogoutHandler : public RequestHandler {
private:
  User_sessions* sessions;
public:
  Response *callback(Request *req);
  LogoutHandler(User_sessions* _sessions){
    sessions = _sessions;
  }
};

class GetDisplaynameHandler : public RequestHandler {
private:
	Jeekjeek* jeekjeek;
	User_sessions* sessions;
public:
  Response *callback(Request *req);

  GetDisplaynameHandler(Jeekjeek* _jeekjeek, User_sessions* _sessions){
    jeekjeek = _jeekjeek;
    sessions = _sessions;
  }
};

class RejeekHandler : public RequestHandler {
private:
	Jeekjeek* jeekjeek;
	User_sessions* sessions;
public:
  Response *callback(Request *req);
  RejeekHandler(Jeekjeek* _jeekjeek, User_sessions* _sessions){
    jeekjeek = _jeekjeek;
    sessions = _sessions;
  }
};

class LikeHandler : public RequestHandler {
private:
	Jeekjeek* jeekjeek;
	User_sessions* sessions;
public:
  Response *callback(Request *req);
  LikeHandler(Jeekjeek* _jeekjeek, User_sessions* _sessions){
    jeekjeek = _jeekjeek;
    sessions = _sessions;
  }
};

class NumOfLikesHandler : public RequestHandler {
private:
	Jeekjeek* jeekjeek;
public:
  Response *callback(Request *req);
  NumOfLikesHandler(Jeekjeek* _jeekjeek){
    jeekjeek = _jeekjeek;
  }
};

class GetNotificationsHandler : public RequestHandler {
private:
	Jeekjeek* jeekjeek;
	User_sessions* sessions;
public:
  Response *callback(Request *req);
  GetNotificationsHandler(Jeekjeek* _jeekjeek, User_sessions* _sessions){
      jeekjeek = _jeekjeek;
      sessions = _sessions;
  }
};

class GetNumOfNotificationsHandler : public RequestHandler {
private:
	Jeekjeek* jeekjeek;
	User_sessions* sessions;
public:
  Response *callback(Request *req);
  GetNumOfNotificationsHandler(Jeekjeek* _jeekjeek, User_sessions* _sessions){
      jeekjeek = _jeekjeek;
      sessions = _sessions;
  }
};

class NewJeekHandler : public RequestHandler {
private:
	Jeekjeek* jeekjeek;
	User_sessions* sessions;
public:
  Response *callback(Request *req);
  NewJeekHandler(Jeekjeek* _jeekjeek, User_sessions* _sessions){
    jeekjeek = _jeekjeek;
    sessions = _sessions;
  }
};



string generate_id();
string get_user_jeeks(Jeekjeek* jeekjeek, string search_text, string username);
string get_hashtag_jeeks(Jeekjeek* jeekjeek, string search_text, string username);
string get_html_jeeks_cards_from_jeeks_ids(Jeekjeek* jeekjeek, vector<string> jeek_ids, string username);
string get_all_jeeks(Jeekjeek* jeekjeek, string username, int num_of_jeeks = 20);
string get_html_notifications(vector<string> notifications);
const vector<string> explode(const string& s, const char& c);
bool has_illegal_char(string s);
void replace_string(std::string& str, const std::string& from, const std::string& to);



#endif
