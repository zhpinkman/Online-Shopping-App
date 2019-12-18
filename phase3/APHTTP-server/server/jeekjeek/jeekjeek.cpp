#include "jeekjeek.hpp"

#define ERR_LOGIN "You are not logedin!"

void Jeekjeek::signup(string username, string display_name, string password){
	users.add_user(username, display_name, password);
}

void Jeekjeek::login(string username, string password){
	logedin_user = users.login(username, password);
}

void Jeekjeek::logout(){
	logedin_user = NULL;
}

void Jeekjeek::jeek(string text, vector<string> hashtags, vector<string> mention_usernames){
	if(logedin_user == NULL){
		throw ERR_LOGIN;
	}else{
		vector<User*> mentions = users.username_to_userpointer(mention_usernames);
		Jeek* new_jeek_pointer = jeeks.add_jeek(logedin_user ,text, hashtags, mentions);
		logedin_user->add_jeek(new_jeek_pointer);
	}
}

void Jeekjeek::show_jeek(string jeek_id){
	jeeks.show_jeek(jeek_id);
}

void Jeekjeek::show_user_jeeks(string username){
	users.show_user_jeeks(username);
}
void Jeekjeek::show_hashtag_jeeks(string hashtag){
	jeeks.show_hashtag_jeeks(hashtag);
}

void Jeekjeek::add_comment_to_jeek(string jeek_id, string text){
	if(logedin_user == NULL){
		throw ERR_LOGIN;
	}else{
		jeeks.add_comment_to_jeek(logedin_user, jeek_id, text);
	}
}

void Jeekjeek::add_reply_to_reply(string reply_id, string text){
	if(logedin_user == NULL){
		throw ERR_LOGIN;
	}else{
		jeeks.add_reply_to_reply(logedin_user, reply_id, text);
	}
}


bool Jeekjeek::is_user_logedin(){
	if(logedin_user == NULL){
		return false;
	}else{
		return true;
	}
}

void Jeekjeek::show_reply(string reply_id){
	jeeks.show_reply(reply_id);
}

void Jeekjeek::rejeek(string jeek_id){
	if(logedin_user == NULL){
		throw ERR_LOGIN;
	}else{
		Jeek* new_jeek_pointer = jeeks.rejeek(logedin_user, jeek_id);
		logedin_user->add_jeek(new_jeek_pointer);
	}
}

void Jeekjeek::like_jeek(string jeek_id){
	if(logedin_user == NULL){
		throw ERR_LOGIN;
	}else{
		jeeks.like_jeek(logedin_user, jeek_id);
	}
}

void Jeekjeek::dislike_jeek(string jeek_id){
	if(logedin_user == NULL){
		throw ERR_LOGIN;
	}else{
		jeeks.dislike_jeek(logedin_user, jeek_id);
	}
}

void Jeekjeek::follow_user(string username){
	if(logedin_user == NULL){
		throw ERR_LOGIN;
	}else{
		users.add_follower(username, logedin_user);
		users.add_following(logedin_user, username);
	}
}

void Jeekjeek::unfollow_user(string username){
	if(logedin_user == NULL){
		throw ERR_LOGIN;
	}else{
		users.remove_follower(username, logedin_user);
		users.remove_following(logedin_user, username);
	}
}

void Jeekjeek::show_notifications(){
	if(logedin_user == NULL){
		throw ERR_LOGIN;
	}else{
		logedin_user->show_notifications();
	}
}











vector<string> Jeekjeek::get_jeeks_ids_by_user(string username){
	return users.get_jeeks_ids_by_user(username);
}

vector<string> Jeekjeek::get_jeeks_ids_by_hashtag(string hashtag){
	return jeeks.get_jeeks_ids_by_hashtag(hashtag);
}

vector<string> Jeekjeek::get_jeeks_ids(int num_of_jeeks){
	return jeeks.get_jeeks_ids(num_of_jeeks);
}

Jeek* Jeekjeek::get_jeek_by_id(string jeek_id){
	return jeeks.find_jeek_by_id(jeek_id);
}

string Jeekjeek::get_user_display_name(string username){
	return users.get_user_display_name(username);
}

bool Jeekjeek::has_user_liked_jeek(string username, string jeek_id){
	return jeeks.has_user_liked_jeek(username, jeek_id);
}

vector<string> Jeekjeek::get_notifications_by_username(string username){
	return users.get_notifications_by_username(username);
}

int Jeekjeek::get_num_of_notifications_by_username(string username){
	return users.get_num_of_notifications_by_username(username);
}

void Jeekjeek::make_account_official(string username){
	users.make_account_official(username);
}