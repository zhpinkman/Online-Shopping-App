#include "user.hpp"

void User::print_jeeks(){
	for(int i=0; i<jeeks.size(); i++){
		jeeks[i]->print_jeek_list_mode();
		cout << endl;
	}
}

vector<string> User::get_jeeks_ids(){
	vector<string> jeeks_ids;
	for(int i=0; i<jeeks.size(); i++){
		jeeks_ids.push_back(jeeks[i]->get_id());
	}
	return jeeks_ids;
}

void User::add_follower(User* logedin_user){
	if ( find(followers.begin(), followers.end(), logedin_user) == followers.end() ){
		followers.push_back(logedin_user);
	}
}

void User::add_following(User* user){
	if ( find(following.begin(), following.end(), user) == following.end() ){
		following.push_back(user);
	}
}

void User::remove_follower(User* logedin_user){
	if ( find(followers.begin(), followers.end(), logedin_user) != followers.end() ){
		followers.erase( find(followers.begin(), followers.end(), logedin_user) );
	}
}

void User::remove_following(User* user){
	if ( find(following.begin(), following.end(), user) != following.end() ){
		following.erase( find(following.begin(), following.end(), user) );
	}
}

void User::add_notification_to_followers(string notif){
	for(int i=0; i<followers.size(); i++){
		followers[i]->add_notification(notif);
	}
}

void User::show_notifications(){
	for(int i=0; i<notifications.size(); i++){
		cout << notifications[i];
	}
	notifications.clear();
}

void User::add_notification(string notif){
	notifications.insert(notifications.begin(), notif);
}

void User::make_account_official(){
	if(display_name[display_name.size()-1] != '>'){
		 display_name += " <i class=\"fa fa-check-circle\" style=\"color:#1da1f2\"></i>";
	}
}

bool Users::is_username_duplicated(string username){
	bool is_duplicated = false;
	for(int i=0;i<myusers.size();i++){
		if(myusers[i]->get_username() == username){
			is_duplicated = true;
		}
	}
	return is_duplicated;
}

bool Users::add_user(string username, string display_name, string password){
	if(username!="" && display_name!="" && password!=""){
		if(username.size() > USER_STRINGS_LIMIT || display_name.size() > USER_STRINGS_LIMIT || password.size() > USER_STRINGS_LIMIT){
			throw "Characters limit exceeded (max: 30 characters)";
		}
		if(!is_username_duplicated(username)){
			User* new_user = new User(username, display_name, password);
			myusers.push_back(new_user);
			return true;
		}else{
			throw "Error: Duplicate Username";
			return false;
		}
	}else{
		throw "Error: Empty fields or White spaces";
		return false;
	}
}

User* Users::login(string username, string password){
	User* logedin_user = find_user_by_username(username);
	
	if(logedin_user == NULL){
		throw "Wrong username";
	}else if(logedin_user->get_password() != password){
		throw "Wrong password";
	}

	return logedin_user;
}

User* Users::find_user_by_username(string username){
	for(int i=0;i<myusers.size();i++){
		if(myusers[i]->get_username() == username){
			return myusers[i];
		}
	}
	return NULL;
}

vector<User*> Users::username_to_userpointer(vector<string> mention_usernames){
	vector<User*> mentions;
	for(int i=0;i<myusers.size();i++){
		for(int j=0; j<mention_usernames.size(); j++){
			if(myusers[i]->get_username() == mention_usernames[j]){
				mentions.push_back(myusers[i]);
			}
		}
	}
	return mentions;
}

void Users::show_user_jeeks(string username){
	User* user = find_user_by_username(username);
	if(user == NULL){
		throw "Username not found!";
	}else{
		user->print_jeeks();
	}
}

void Users::add_follower(string username, User* logedin_user){
	User* user = find_user_by_username(username);
	if(user == NULL){
		throw "Username not found!";
	}else{
		user->add_follower(logedin_user);
	}
}

void Users::remove_follower(string username, User* logedin_user){
	User* user = find_user_by_username(username);
	if(user == NULL){
		throw "Username not found!";
	}else{
		user->remove_follower(logedin_user);
	}
}

void Users::add_following(User* logedin_user, string username){
	User* user = find_user_by_username(username);
	if(user == NULL){
		throw "Username not found!";
	}else{
		logedin_user->add_following(user);
	}
}

void Users::remove_following(User* logedin_user, string username){
	User* user = find_user_by_username(username);
	if(user == NULL){
		throw "Username not found!";
	}else{
		logedin_user->remove_following(user);
	}
}



vector<string> Users::get_jeeks_ids_by_user(string username){
	User* user = find_user_by_username(username);
	if(user == NULL){
		throw "Username not found!";
	}else{
		return user->get_jeeks_ids();
	}
}

string Users::get_user_display_name(string username){
	User* user = find_user_by_username(username);
	if(user == NULL){
		throw "Username not found!";
	}else{
		return user->get_display_name();
	}
}

vector<string> User::get_notifications(){
	vector<string> temp_notif = notifications;
	notifications.clear();
	return temp_notif;
}

vector<string> Users::get_notifications_by_username(string username){
	User* user = find_user_by_username(username);
	if(user == NULL){
		throw "Username not found!";
	}else{
		return user->get_notifications();
	}
}

int Users::get_num_of_notifications_by_username(string username){
	User* user = find_user_by_username(username);
	if(user == NULL){
		throw "Username not found!";
	}else{
		return user->get_num_of_notifications();
	}
}

void Users::make_account_official(string username){
	User* user = find_user_by_username(username);
	if(user == NULL){
		throw "Username not found!";
	}else{
		user->make_account_official();
	}
}