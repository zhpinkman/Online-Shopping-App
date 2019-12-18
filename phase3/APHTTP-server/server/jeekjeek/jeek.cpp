#include "jeek.hpp"
#include "user.hpp"

Jeek::Jeek(string _id, User* _jeeker, string _text, vector<string> _hashtags, vector<User*> _mentions){
	id = _id;
	jeeker = _jeeker;
	text = _text;
	hashtags = _hashtags;
	mentions = _mentions;
}

void Jeek::print_jeek(){
	cout << jeeker->get_display_name() << endl;
	cout << text << endl;
	for(int i=0; i<hashtags.size(); i++){
		cout << "#" << hashtags[i] << endl;
	}
	for(int i=0; i<mentions.size(); i++){
		cout << "@" << mentions[i]->get_username() << endl;
	}
	cout << "Likes: " << likers.size() << endl;
	cout << "Rejeeks: " << rejeekers.size() << endl;
	cout << "Comments:" << endl;
	comments.print_ids();
}

void Jeek::print_jeek_list_mode(){
	cout << id << " " << jeeker->get_display_name() << endl;
	cout << text << endl;
}

bool Jeek::has_hashtag(string hashtag){
	for(int i=0; i<hashtags.size(); i++){
		if(hashtags[i] == hashtag){
			return true;
		}
	}
	return false;
}

void Jeek::add_comment_to_jeek(User* replier, string text){
	if(text == ""){
		throw "Reply Text is not valid!";
	}else{
		comments.add_reply(replier, text, id);
		jeeker->add_notification( replier->get_username() + " commented on " + id);
	}
}

void Jeek::add_reply_to_reply(User* replier, string reply_to_id, string text){
	comments.add_reply_to_reply(replier, reply_to_id, text);
}

void Jeek::show_reply(string reply_id){
	comments.show_reply(reply_id);
}

void Jeek::add_rejeeker(User* rejeeker){
	if ( find(rejeekers.begin(), rejeekers.end(), rejeeker) == rejeekers.end() ){
		rejeekers.push_back(rejeeker);
	}
}

void Jeek::like_jeek(User* logedin_user){
	if ( find(likers.begin(), likers.end(), logedin_user) == likers.end() ){
		likers.push_back(logedin_user);

		jeeker->add_notification( logedin_user->get_username() + " liked " + id);
	}
}

void Jeek::dislike_jeek(User* logedin_user){
	if ( find(likers.begin(), likers.end(), logedin_user) != likers.end() ){
		likers.erase( find(likers.begin(), likers.end(), logedin_user) );

		jeeker->add_notification( logedin_user->get_username() + " disliked " + id);
	}
}

bool Jeek::has_user_liked_jeek(string username){
	for(int i=0; i<likers.size(); i++){
		if(likers[i]->get_username() == username){
			return true;
		}
	}
	return false;
}



Jeek* Jeeks::add_jeek(User* jeeker, string text, vector<string> hashtags, vector<User*> mentions){
	if(text.size() > TEXT_CHAR_LIMIT){
		throw "Jeek Text is more than 300 characters!";
	}else if(text == ""){
		throw "Jeek Text is not set!";
	}else{
		int id_count = jeeks.size();
		string id = "jeek_id_" + to_string(id_count);

		Jeek* new_jeek = new Jeek(id, jeeker, text, hashtags, mentions);
		jeeks.push_back(new_jeek);

		jeeker->add_notification_to_followers( jeeker->get_username() + " jeeked " + id);
		for(int i=0; i<mentions.size(); i++){
			mentions[i]->add_notification( jeeker->get_username() + " mentioned you in " + id );
		}

		return new_jeek;
	}
}

Jeek* Jeeks::find_jeek_by_id(string jeek_id){
	for(int i=0; i<jeeks.size(); i++){
		if(jeeks[i]->get_id() == jeek_id){
			return jeeks[i];
		}
	}
}

void Jeeks::show_jeek(string jeek_id){
	Jeek* jeek = find_jeek_by_id(jeek_id);
	if(jeek == NULL){
		throw "Jeek not found!";
	}else{
		jeek->print_jeek();
	}
}

void Jeeks::show_hashtag_jeeks(string hashtag){
	for(int i=0; i<jeeks.size(); i++){
		if(jeeks[i]->has_hashtag(hashtag) == true){
			jeeks[i]->print_jeek_list_mode();
		}
	}
}

void Jeeks::add_comment_to_jeek(User* replier, string jeek_id, string text){
	Jeek* jeek = find_jeek_by_id(jeek_id);
	if(jeek == NULL){
		throw "Jeek not found!";
	}else{
		jeek->add_comment_to_jeek(replier, text);
	}
}

void Jeeks::add_reply_to_reply(User* replier, string reply_to_id, string text){
	for(int i=0; i<jeeks.size(); i++){
		jeeks[i]->add_reply_to_reply(replier, reply_to_id, text);
	}
}

void Jeeks::show_reply(string reply_id){
	for(int i=0; i<jeeks.size(); i++){
		jeeks[i]->show_reply(reply_id);
	}
}

Jeek* Jeeks::rejeek(User* jeeker, string jeek_id){
	Jeek* from_jeek = find_jeek_by_id(jeek_id);
	if(from_jeek == NULL){
		throw "JeekId not found!";
	}else{
		from_jeek->add_rejeeker(jeeker);

		string rejeeked = REJEEKED;
		string text;
		if(from_jeek->get_text().substr(0, rejeeked.size()) == rejeeked){
			text = from_jeek->get_text();
		}else{
			text = rejeeked + from_jeek->get_text();
		}

		int id_count = jeeks.size();
		string id = "jeek_id_" + to_string(id_count);
		vector<string> hashtags;
		vector<User*> mentions;
		Jeek* new_jeek = new Jeek(id, jeeker, text, hashtags, mentions);
		jeeks.push_back(new_jeek);

		from_jeek->get_jeeker()->add_notification( jeeker->get_username() + " rejeeked " + jeek_id );

		return new_jeek;
	}
}

void Jeeks::like_jeek(User* logedin_user, string jeek_id){
	Jeek* jeek = find_jeek_by_id(jeek_id);
	if(jeek == NULL){
		throw "JeekId not found!";
	}else{
		jeek->like_jeek(logedin_user);
	}
}

void Jeeks::dislike_jeek(User* logedin_user, string jeek_id){
	Jeek* jeek = find_jeek_by_id(jeek_id);
	if(jeek == NULL){
		throw "JeekId not found!";
	}else{
		jeek->dislike_jeek(logedin_user);
	}
}


vector<string> Jeeks::get_jeeks_ids_by_hashtag(string hashtag){
	vector<string> hashtags;
	for(int i=0; i<jeeks.size(); i++){
		if(jeeks[i]->has_hashtag(hashtag) == true){
			hashtags.push_back(jeeks[i]->get_id());
		}
	}
	if(hashtags.size() == 0){
		throw "Hashtag not found!";
	}
	return hashtags;
}

vector<string> Jeeks::get_jeeks_ids(int num_of_jeeks){
	vector<string> return_jeeks;
	int start_pos = jeeks.size()-num_of_jeeks;
	if(start_pos < 0){
		start_pos = 0;
	}
	for(int i=start_pos; i<jeeks.size(); i++){
		cerr << i << endl;
		return_jeeks.push_back(jeeks[i]->get_id());
	}
	return return_jeeks;
}

bool Jeeks::has_user_liked_jeek(string username, string jeek_id){
	Jeek* jeek = find_jeek_by_id(jeek_id);
	if(jeek == NULL){
		throw "JeekId not found!";
	}else{
		return jeek->has_user_liked_jeek(username);
	}
}