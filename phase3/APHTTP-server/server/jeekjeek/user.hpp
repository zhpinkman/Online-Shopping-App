#ifndef __USER_H__
#define __USER_H__

#include <vector>
#include <string>
#include <algorithm>
#include "jeek.hpp"

using namespace std;

#define USER_STRINGS_LIMIT 30

class User{
private:
	string username;
	string display_name;
	string password;
	vector<Jeek*> jeeks;
	vector<User*> following;
	vector<User*> followers;
	vector<string> notifications;

public:
	User(string _username, string _display_name, string _password) 
		:username(_username), display_name(_display_name), password(_password) {};
	void add_jeek(Jeek* new_jeek) { jeeks.push_back(new_jeek); } ;
	string get_username() { return username; }
	string get_display_name() { return display_name; }
	string get_password() { return password; }
	void print_jeeks();

	void add_follower(User* logedin_user);
	void add_following(User* user);
	void remove_follower(User* logedin_user);
	void remove_following(User* user);

	void show_notifications();
	void add_notification(string notif);
	void add_notification_to_followers(string notif);


	vector<string> get_jeeks_ids();
	vector<string> get_notifications();
	int get_num_of_notifications() { return notifications.size(); }
	void make_account_official();

};


class Users{
private:
	vector<User*> myusers;
	bool is_username_duplicated(string username);
public:
	bool add_user(string username, string display_name, string password);
	User* find_user_by_username(string username);
	User* login(string username, string password);
	void show_user_jeeks(string username);
	void add_follower(string username, User* logedin_user);
	void add_following(User* logedin_user, string username);
	void remove_follower(string username, User* logedin_user);
	void remove_following(User* logedin_user, string username);

	vector<User*> username_to_userpointer(vector<string> mention_usernames);



	vector<string> get_jeeks_ids_by_user(string username);
	string get_user_display_name(string username);
	vector<string> get_notifications_by_username(string username);
	int get_num_of_notifications_by_username(string username);
	void make_account_official(string username);

};

#endif