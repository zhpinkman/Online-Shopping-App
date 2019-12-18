#include "cin_interface.hpp"

void Cin_interface::run(Jeekjeek& myjeekjeek){
	string command;
	bool terminate_run = false;
	while(terminate_run == false){
		cin >> command;
		try{
		
			if(command == CMD_SIGNUP){
				string username, display_name, password;
				cin >> username >> display_name >> password;
				myjeekjeek.signup(username, display_name, password);
			
			}else if(command == CMD_LOGIN){
				string username, password;
				cin >> username >> password;
				myjeekjeek.login(username, password);
			
			}else if(command == CMD_LOGOUT){
				myjeekjeek.logout();
			
			}else if(command == CMD_JEEK){
				if(myjeekjeek.is_user_logedin()){
					string sub_commnd;
					string text = "";
					vector<string> hashtags;
					vector<string> mention_usernames;
					string tmp_mention_username;
					string tmp_hashtag;
					
					bool end_of_input = false;
					while(end_of_input == false){
						cin >> sub_commnd;
						if(sub_commnd == SUB_CMD_PUBLISH){
							myjeekjeek.jeek(text, hashtags, mention_usernames);
							end_of_input = true;
						}else if(sub_commnd == SUB_CMD_ABORT){
							end_of_input = true;
						}else if(sub_commnd == SUB_CMD_TEXT){
							cin.ignore();
							getline(cin, text);
						}else if(sub_commnd == SUB_CMD_MENTION){
							cin >> tmp_mention_username;
							mention_usernames.push_back(tmp_mention_username);
						}else if(sub_commnd == SUB_CMD_HASHTAG){
							cin >> tmp_hashtag;
							hashtags.push_back(tmp_hashtag);
						}else{
							throw "ERROR: SubCommand not found!";
						}
					}
				}else{
					throw "You are not logedin!";
				}
			}else if(command == CMD_SHOWJEEK){
				string jeek_id;
				cin >> jeek_id;
				myjeekjeek.show_jeek(jeek_id);
			}else if(command == CMD_SEARCH){
				string search_word;
				cin >> search_word;
				if(search_word[0] == '@'){
					search_word = search_word.substr(1, search_word.size() - 1);
					myjeekjeek.show_user_jeeks(search_word);
				}else if(search_word[0] == '#'){
					search_word = search_word.substr(1, search_word.size() - 1);
					myjeekjeek.show_hashtag_jeeks(search_word);
				}else{
					throw "search word must be started with @ or #";
				}
			
			}else if(command == CMD_COMMENT){
				string jeek_id;
				cin >> jeek_id;
				cin.ignore();
				string text;
				getline(cin, text);
				myjeekjeek.add_comment_to_jeek(jeek_id, text);

			}else if(command == CMD_REPLY){
				string reply_id;
				cin >> reply_id;
				cin.ignore();
				string text;
				getline(cin, text);
				myjeekjeek.add_reply_to_reply(reply_id, text);

			}else if(command == CMD_SHOWCOMMENT || command == CMD_SHOWREPLY){
				string reply_id;
				cin >> reply_id;
				myjeekjeek.show_reply(reply_id);

			}else if(command == CMD_REJEEK){
				string jeek_id;
				cin >> jeek_id;
				myjeekjeek.rejeek(jeek_id);

			}else if(command == CMD_LIKE){
				string jeek_id;
				cin >> jeek_id;
				myjeekjeek.like_jeek(jeek_id);

			}else if(command == CMD_DISLIKE){
				string jeek_id;
				cin >> jeek_id;
				myjeekjeek.dislike_jeek(jeek_id);

			}else if(command == CMD_FOLLOW){
				string username;
				cin >> username;
				myjeekjeek.follow_user(username);

			}else if(command == CMD_UNFOLLOW){
				string username;
				cin >> username;
				myjeekjeek.unfollow_user(username);

			}else if(command == CMD_NOTIFICATIONS){
				myjeekjeek.show_notifications();

			}else{
				throw "ERROR: Command not found!";
			}
		

		}catch(const char* err){
			cerr << err << endl << endl;
		}
	



	}

}