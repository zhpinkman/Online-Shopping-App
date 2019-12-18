#ifndef __REPLY_H__
#define __REPLY_H__

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Reply;
class User;

class Replies{
private:
	vector<Reply*> replies;
public:
	void add_reply(User* replier, string text, string pre_id);
	void add_reply_to_reply(User* replier, string reply_to_id, string text);
	void show_reply(string reply_id);

	void print_ids();
};

class Reply{
private:
	string id;
	User* replier;
	string text;
	Replies replies;

public:
	Reply(string _id, User* _replier, string _text);
	void add_reply_to_this(User* replier, string text);
	void add_reply_to_reply(User* replier, string reply_to_id, string text);
	void show_reply(string reply_id);
	void print_reply();
	string get_id() { return id; }
};




#endif