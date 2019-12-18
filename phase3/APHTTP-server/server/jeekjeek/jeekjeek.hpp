#ifndef __JEEKJEEK_H__
#define __JEEKJEEK_H__

#include <vector>
#include <string>
#include "user.hpp"
#include "jeek.hpp"
using namespace std;

class Jeekjeek{
private:
	User* logedin_user = NULL; 
	Users users;
	Jeeks jeeks;
public:
	void signup(string username, string display_name, string password);
	void login(string username, string password);
	void logout();

	void jeek(string text, vector<string> hashtags, vector<string> mention_usernames);
	void show_jeek(string jeek_id);
	void show_user_jeeks(string username);
	void show_hashtag_jeeks(string hashtag);
	void add_comment_to_jeek(string jeek_id, string text);
	void add_reply_to_reply(string eply_id, string text);
	void show_reply(string reply_id);
	void rejeek(string jeek_id);
	void like_jeek(string jeek_id);
	void dislike_jeek(string jeek_id);
	void follow_user(string username);
	void unfollow_user(string username);
	void show_notifications();

	bool is_user_logedin();

	vector<string> get_jeeks_ids_by_user(string username);
	vector<string> get_jeeks_ids_by_hashtag(string hashtag);
	Jeek* get_jeek_by_id(string jeek_id);
	string get_user_display_name(string username);
	bool has_user_liked_jeek(string username, string jeek_id);
	vector<string> get_jeeks_ids(int num_of_jeeks);
	vector<string> get_notifications_by_username(string username);
	int get_num_of_notifications_by_username(string username);
	void make_account_official(string username);

};








#endif