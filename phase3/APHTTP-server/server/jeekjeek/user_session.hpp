#ifndef __USER_SESSION__
#define __USER_SESSION__

#include <iostream>
#include <vector>

using namespace std;

class User_session{
public:
	string session_id;
	string username;
	string password;
	User_session(string _id, string _username, string _password){
		session_id = _id;
		username = _username;
		password = _password;
	}
};

class User_sessions{
private:
	vector<User_session*> sessions;
	User_session* find_session_by_id(string session_id);
public:
	void add_session(string _id, string _username, string _password);
	string get_username_by_session_id(string session_id);
	string get_password_by_session_id(string session_id);
	void delete_session_by_id(string session_id);
};

#endif