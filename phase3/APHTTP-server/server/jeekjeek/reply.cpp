#include "reply.hpp"
#include "user.hpp"
Reply::Reply(string _id, User* _replier, string _text){
	id = _id;
	replier = _replier;
	text = _text;
}

void Reply::add_reply_to_this(User* _replier, string text){
	replies.add_reply(_replier, text, id);
	replier->add_notification( _replier->get_username() + " replied " + id);
}

void Reply::add_reply_to_reply(User* replier, string reply_to_id, string text){
	replies.add_reply_to_reply(replier, reply_to_id, text);
}

void Reply::show_reply(string reply_id){
	replies.show_reply(reply_id);
}

void Reply::print_reply(){
	cout << replier->get_display_name() << endl;
	cout << text << endl;
	cout << "replies:" << endl;
	replies.print_ids();
}

void Replies::add_reply(User* replier, string text, string pre_id){
	if(text == ""){
		throw "Reply Text is not valid!";
	}else{
		int id_count = replies.size();
		string id = "reply_id_" + to_string(id_count) + pre_id;

		Reply* new_reply = new Reply(id, replier, text);
		replies.push_back(new_reply);
	}
}

void Replies::add_reply_to_reply(User* replier, string reply_to_id, string text){
	for(int i=0; i<replies.size(); i++){
		if(replies[i]->get_id() == reply_to_id){
			replies[i]->add_reply_to_this(replier, text);
		}
		replies[i]->add_reply_to_reply(replier, reply_to_id, text);
	}
}

void Replies::print_ids(){
	for(int i=0; i<replies.size(); i++){
		cout << replies[i]->get_id() << endl;
	}
}

void Replies::show_reply(string reply_id){
	for(int i=0; i<replies.size(); i++){
		if(replies[i]->get_id() == reply_id){
			replies[i]->print_reply();
		}
		replies[i]->show_reply(reply_id);
	}
}
