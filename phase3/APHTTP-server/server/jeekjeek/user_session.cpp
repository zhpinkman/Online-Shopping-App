#include "user_session.hpp"

void User_sessions::add_session(string _id, string _username, string _password){
	User_session* new_session = new User_session(_id, _username, _password);
	sessions.push_back(new_session);
}

string User_sessions::get_username_by_session_id(string session_id){
	User_session* session = find_session_by_id(session_id);
	if(session == NULL){
		return "";
	}else{
		return session->username;
	}
}

string User_sessions::get_password_by_session_id(string session_id){
	User_session* session = find_session_by_id(session_id);
	if(session == NULL){
		return "";
	}else{
		return session->password;
	}
}

void User_sessions::delete_session_by_id(string session_id){
	for(int i=0; i<sessions.size(); i++){
		if(session_id == sessions[i]->session_id){
			free(sessions[i]);
			sessions.erase(sessions.begin() + i);
		}
	}
}

User_session* User_sessions::find_session_by_id(string session_id){
	for(int i=0; i<sessions.size(); i++){
		if(session_id == sessions[i]->session_id){
			return sessions[i];
		}
	}
	return NULL;
}