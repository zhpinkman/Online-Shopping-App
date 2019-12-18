#ifndef __JEEK_H__
#define __JEEK_H__

#include <iostream>
#include <vector>
#include <string>
#include "reply.hpp"
#include <algorithm>
using namespace std;

#define REJEEKED "Rejeeked: "
#define TEXT_CHAR_LIMIT 300

class User;

class Jeek{
private:
	string id;
	User* jeeker;
	string text;
	vector<string> hashtags;
	vector<User*> mentions;

	vector<User*> likers;
	vector<User*> rejeekers;
	Replies comments;

public:
	Jeek(string id, User* jeeker, string text, vector<string> hashtags, vector<User*> mentions);
	string get_id() { return id; }
	string get_text() { return text; }
	User* get_jeeker() { return jeeker; }
	void print_jeek();
	void print_jeek_list_mode();
	void add_comment_to_jeek(User* replier, string text);
	void add_reply_to_reply(User* replier, string reply_to_id, string text);
	void show_reply(string reply_id);
	void add_rejeeker(User* rejeeker);
	void like_jeek(User* logedin_user);
	void dislike_jeek(User* logedin_user);

	bool has_hashtag(string hashtag);

	vector<string> get_hashtags() { return hashtags; }
	vector<User*> get_mentions() { return mentions; }
	int get_num_of_likes() { return likers.size(); }
	int get_num_of_rejeeks() { return rejeekers.size(); }
	bool has_user_liked_jeek(string username);
};


class Jeeks{
private:
	vector<Jeek*> jeeks;
public:
	Jeek* add_jeek(User* jeeker, string text, vector<string> hashtags, vector<User*> mentions);
	Jeek* find_jeek_by_id(string jeek_id);
	void show_jeek(string jeek_id);
	void show_hashtag_jeeks(string hashtag);
	void add_comment_to_jeek(User* replier, string jeek_id, string text);
	void add_reply_to_reply(User* replier, string reply_to_id, string text);
	void show_reply(string reply_id);
	Jeek* rejeek(User* jeeker, string jeek_id);
	void like_jeek(User* logedin_user, string jeek_id);
	void dislike_jeek(User* logedin_user, string jeek_id);


	vector<string> get_jeeks_ids_by_hashtag(string hashtag);
	vector<string> get_jeeks_ids(int num_of_jeeks);
	bool has_user_liked_jeek(string username, string jeek_id);

};

#endif