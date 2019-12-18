#include "handlers.hpp"

#define PARAM_USERNAME "username"
#define PARAM_PASSWORD "password"
#define PARAM_DISPLAY_NAME "display_name"
#define PARAM_SEARCH_TEXT "search_text"
#define PARAM_SEARCH_TYPE "search_type"
#define PARAM_JEEK_ID "jeek_id"
#define PARAM_LIKE_STATE "like_state"
#define PARAM_LIKE_STATE_TRUE_VALUE "true"
#define PARAM_NEW_JEEK_TEXT "text"
#define PARAM_NEW_JEEK_MENTIONS "mentions"
#define PARAM_NEW_JEEK_HASHTAGS "hashtags"
#define AJAX_POST_SPACE_CHAR "SPACE_CHAR"

#define THROW_ILLEGAL_CHAR_ERR "Illegal characters userd!"
#define TEXT_NO_NOTIFICATIONS "No Notifications"

#define JEEK_CARD_HTML_URL "htmlFiles/home/jeek_card/index.html"
#define JEEK_CARD_MODAL_ID "MODAL_ID"
#define JEEK_CARD_DISPLAY_NAME "DISPLAY_NAME"
#define JEEK_CARD_USERNAME "USERNAME"
#define JEEK_CARD_JEEK_TEXT_SMALL "JEEK_TEXT_SMALL"
#define JEEK_CARD_JEEK_TEXT "JEEK_TEXT"
#define JEEK_CARD_JEEK_HASHTAGS "HASHTAGS"
#define JEEK_CARD_JEEK_MENTIONS "MENTIONS"
#define JEEK_CARD_NUM_OF_REJEEKS "NUM_OF_REJEEKS"
#define JEEK_CARD_NUM_OF_LIKES "NUM_OF_LIKES"
#define JEEK_CARD_JEEK_ID "JEEK_ID"
#define JEEK_CARD_LIKE_BUTTON_CHECK_STATE "CHECKSTATE"


Response* LoginHandler::callback(Request *req) {
  Response *res = new Response;
  string username = req->getBodyParam(PARAM_USERNAME);
  string password = req->getBodyParam(PARAM_PASSWORD);
  cerr << "Received Data: " << username << " - " << password << endl;

  string response;
  try{
    if(has_illegal_char(username) || has_illegal_char(password)){
      throw THROW_ILLEGAL_CHAR_ERR;
    }
    jeekjeek->login(username, password);
    response = SUCCESS;

    string session_id = generate_id();
    sessions->add_session(session_id, username, password);
    res->setSessionId(session_id);

  }catch(const char* err){
    response = err;
  }

  res->setHeader("Content-Type", "text/html");
  res->setBody(response);
  return res;
}

  


Response* SignupHandler::callback(Request *req) {
  Response *res = new Response;
  string username = req->getBodyParam(PARAM_USERNAME);
  string password = req->getBodyParam(PARAM_PASSWORD);
  string display_name = req->getBodyParam(PARAM_DISPLAY_NAME);
  string response;
  try{
    if(has_illegal_char(username) || has_illegal_char(password) || has_illegal_char(display_name)){
      throw THROW_ILLEGAL_CHAR_ERR;
    }
    jeekjeek->signup(username, display_name, password);
    response = SUCCESS;

  }catch(const char* err){
    response = err;
  }

  res->setHeader("Content-Type", "text/html");
  res->setBody(response);
  return res;
}


Response* SearchHandler::callback(Request *req) {
  Response *res = new Response;
  string search_text = req->getBodyParam(PARAM_SEARCH_TEXT);
  string search_type = req->getBodyParam(PARAM_SEARCH_TYPE);
  cerr << "Received Data: " << search_text << endl;

  string response;
  try{
      if(has_illegal_char(search_text) || has_illegal_char(search_type)){
        throw THROW_ILLEGAL_CHAR_ERR;
      }
      string session_id = req->getSessionId();
      string username = sessions->get_username_by_session_id(session_id);
      if(search_text == ""){
        response = get_all_jeeks(jeekjeek, username);
      }else if(search_type == SEARCH_TYPE_USERS){
        response = get_user_jeeks(jeekjeek, search_text, username);
      }else if(search_type == SEARCH_TYPE_HASHTAGS){
        response = get_hashtag_jeeks(jeekjeek, search_text, username);
      }


  }catch(const char* err){
    response = err;
  }

  res->setHeader("Content-Type", "text/html");
  res->setBody(response);
  return res;
}


Response* GetUsernameHandler::callback(Request *req) {
  Response *res = new Response;
  string response;
  try{
      string session_id = req->getSessionId();
      response = sessions->get_username_by_session_id(session_id);
  }catch(const char* err){
    response = err;
  }
  
  res->setHeader("Content-Type", "text/html");
  res->setBody(response);
  return res;
}



Response* LogoutHandler::callback(Request *req) {
  Response *res = new Response;
  string response = "";
  try{
      string session_id = req->getSessionId();
      sessions->delete_session_by_id(session_id);
      res->setSessionId("");
      response = SUCCESS;
  }catch(const char* err){
    response = err;
  }
  
  res->setHeader("Content-Type", "text/html");
  res->setBody(response);
  return res;
}



Response* GetDisplaynameHandler::callback(Request *req) {
  Response *res = new Response;
  string response;
  try{
    string session_id = req->getSessionId();
    response = jeekjeek->get_user_display_name( sessions->get_username_by_session_id(session_id) );
  }catch(const char* err){
    response = err;
  }
  res->setHeader("Content-Type", "text/html");
  res->setBody(response);
  return res;
}




Response* RejeekHandler::callback(Request *req) {
  Response *res = new Response;
  string response;
  try{
    string session_id = req->getSessionId();
    string jeek_id = req->getBodyParam(PARAM_JEEK_ID);
    if(has_illegal_char(jeek_id)){
      throw THROW_ILLEGAL_CHAR_ERR;
    }
    string username = sessions->get_username_by_session_id(session_id);
    string password = sessions->get_password_by_session_id(session_id);
    cerr << jeek_id << endl;
    jeekjeek->login(username, password);
    jeekjeek->rejeek(jeek_id);
    response = SUCCESS;
  }catch(const char* err){
    response = err;
  }
  res->setHeader("Content-Type", "text/html");
  res->setBody(response);
  return res;
}



Response* LikeHandler::callback(Request *req) {
  Response *res = new Response;
  string response;
  try{
    string session_id = req->getSessionId();
    string jeek_id = req->getBodyParam(PARAM_JEEK_ID);
    string like_state = req->getBodyParam(PARAM_LIKE_STATE);
    if(has_illegal_char(jeek_id) || has_illegal_char(like_state)){
      throw THROW_ILLEGAL_CHAR_ERR;
    }
    string username = sessions->get_username_by_session_id(session_id);
    string password = sessions->get_password_by_session_id(session_id);
    cerr << jeek_id << endl;
    jeekjeek->login(username, password);

    if(like_state == PARAM_LIKE_STATE_TRUE_VALUE){
      jeekjeek->like_jeek(jeek_id);
    }else{
      jeekjeek->dislike_jeek(jeek_id);
    }
    response = SUCCESS;

  }catch(const char* err){
    response = err;
  }
  res->setHeader("Content-Type", "text/html");
  res->setBody(response);
  return res;
}



Response* NumOfLikesHandler::callback(Request *req) {
  Response *res = new Response;
  string response;
  try{
    string jeek_id = req->getBodyParam(PARAM_JEEK_ID);
    if(has_illegal_char(jeek_id)){
      throw THROW_ILLEGAL_CHAR_ERR;
    }
    cerr << jeek_id << endl;
    response = to_string( jeekjeek->get_jeek_by_id(jeek_id)->get_num_of_likes() );

  }catch(const char* err){
    response = err;
  }
  res->setHeader("Content-Type", "text/html");
  res->setBody(response);
  return res;
}


Response* GetNotificationsHandler::callback(Request *req) {
  Response *res = new Response;
  string response;
  try{
    string session_id = req->getSessionId();
    string username = sessions->get_username_by_session_id(session_id);
    vector<string> notifications = jeekjeek->get_notifications_by_username(username);
    response = get_html_notifications(notifications);
  }catch(const char* err){
    response = err;
  }
  res->setHeader("Content-Type", "text/html");
  res->setBody(response);
  return res;
}



Response* GetNumOfNotificationsHandler::callback(Request *req) {
  Response *res = new Response;
  string response;
  try{
    string session_id = req->getSessionId();
    string username = sessions->get_username_by_session_id(session_id);
    response = to_string(jeekjeek->get_num_of_notifications_by_username(username));
  }catch(const char* err){
    response = err;
  }
  res->setHeader("Content-Type", "text/html");
  res->setBody(response);
  return res;
}

   


Response* NewJeekHandler::callback(Request *req) {
  Response *res = new Response;
  string response;
  try{
    string session_id = req->getSessionId();
    string new_jeek_text = req->getBodyParam(PARAM_NEW_JEEK_TEXT);
    replace_string(new_jeek_text, AJAX_POST_SPACE_CHAR, " ");
    vector<string> hashtags = explode(req->getBodyParam(PARAM_NEW_JEEK_HASHTAGS), ' ');
    vector<string> mentions = explode(req->getBodyParam(PARAM_NEW_JEEK_MENTIONS), ' ');
    string username = sessions->get_username_by_session_id(session_id);
    string password = sessions->get_password_by_session_id(session_id);

    replace_string(new_jeek_text, "<br>", "BR_TAG_LEGAL");
    if(has_illegal_char(new_jeek_text) || has_illegal_char(req->getBodyParam(PARAM_NEW_JEEK_HASHTAGS)) || has_illegal_char(req->getBodyParam(PARAM_NEW_JEEK_MENTIONS))){
      throw THROW_ILLEGAL_CHAR_ERR;
    }
    replace_string(new_jeek_text, "BR_TAG_LEGAL", "<br>");

    jeekjeek->login(username, password);
    jeekjeek->jeek(new_jeek_text, hashtags, mentions);
    cerr << new_jeek_text << endl;

    response = SUCCESS;
  }catch(const char* err){
    response = err;
  }
  res->setHeader("Content-Type", "text/html");
  res->setBody(response);
  return res;
}









string generate_id(){
  srand (time(NULL));
  return to_string(rand() % 100000);
}

string get_user_jeeks(Jeekjeek* jeekjeek, string search_text, string username){
	string response = "";
	vector<string> user_jeeks_ids = jeekjeek->get_jeeks_ids_by_user(search_text);
	response = get_html_jeeks_cards_from_jeeks_ids(jeekjeek, user_jeeks_ids, username);
	return response;
}

string get_hashtag_jeeks(Jeekjeek* jeekjeek, string search_text, string username){
	string response = "";
	vector<string> hashtag_jeeks_ids = jeekjeek->get_jeeks_ids_by_hashtag(search_text);
	response = get_html_jeeks_cards_from_jeeks_ids(jeekjeek, hashtag_jeeks_ids, username);
	return response;
}

string get_all_jeeks(Jeekjeek* jeekjeek, string username, int num_of_jeeks){
  string response = "";
	vector<string> jeeks_ids = jeekjeek->get_jeeks_ids(num_of_jeeks);
	response = get_html_jeeks_cards_from_jeeks_ids(jeekjeek, jeeks_ids, username);
	return response;
}

void replace_string(std::string& str, const std::string& from, const std::string& to) {
    bool is_string_exist = true;
    size_t start_pos;
    while(is_string_exist){
      start_pos = str.find(from);
      if(start_pos == std::string::npos){
          is_string_exist = false;
      }else{
        str.replace(start_pos, from.length(), to);
      }
    }
}

string get_html_jeeks_cards_from_jeeks_ids(Jeekjeek* jeekjeek, vector<string> jeek_ids, string username){
	string response = "";
	for(int i=jeek_ids.size()-1; i>=0; i--){
		Jeek* jeek = jeekjeek->get_jeek_by_id(jeek_ids[i]);
		vector<string> hashtags = jeek->get_hashtags();
		vector<User*> mentions = jeek->get_mentions();
		
		string html_hashtags = "";
		for(int i=0; i<hashtags.size(); i++){
			html_hashtags = html_hashtags + "<a style=\"cursor: pointer;\">#" + hashtags[i] + "</a><br>";
		}
		string html_mentions = "";
		for(int i=0; i<mentions.size(); i++){
			html_mentions = html_mentions + "<a style=\"cursor: pointer;\">@" + mentions[i]->get_username() + "</a><br>";
		}

    string jeek_html = readFile(JEEK_CARD_HTML_URL);
    replace_string(jeek_html, JEEK_CARD_MODAL_ID, "modal"+to_string(i));
    replace_string(jeek_html, JEEK_CARD_DISPLAY_NAME, jeek->get_jeeker()->get_display_name() );
    replace_string(jeek_html, JEEK_CARD_USERNAME, "@"+jeek->get_jeeker()->get_username() );
    string small_text = jeek->get_text();
    replace_string(small_text, "<br>", ". " );
    replace_string(jeek_html, JEEK_CARD_JEEK_TEXT_SMALL, small_text );
    replace_string(jeek_html, JEEK_CARD_JEEK_TEXT, jeek->get_text() );
    replace_string(jeek_html, JEEK_CARD_JEEK_HASHTAGS, html_hashtags );
    replace_string(jeek_html, JEEK_CARD_JEEK_MENTIONS, html_mentions );
    replace_string(jeek_html, JEEK_CARD_NUM_OF_REJEEKS, to_string(jeek->get_num_of_rejeeks()) );
    replace_string(jeek_html, JEEK_CARD_NUM_OF_LIKES, to_string(jeek->get_num_of_likes()) );
    replace_string(jeek_html, JEEK_CARD_JEEK_ID, jeek->get_id() );

    if(jeekjeek->has_user_liked_jeek(username, jeek->get_id())){
      replace_string(jeek_html, JEEK_CARD_LIKE_BUTTON_CHECK_STATE, "checked" );
    }else{
      replace_string(jeek_html, JEEK_CARD_LIKE_BUTTON_CHECK_STATE, "" );
    }

		response = response + jeek_html;


	}
	return response;
}


string get_html_notifications(vector<string> notifications){
  string response = "";
  for(int i=0; i<notifications.size(); i++){
    response = response + notifications[i] + "<hr>";
  }
  if(response == ""){
    response = TEXT_NO_NOTIFICATIONS;
  }
  return response;
}

const vector<string> explode(const string& s, const char& c){
	string buff{""};
	vector<string> v;
	
	for(auto n:s)
	{
		if(n != c) buff+=n; else
		if(n == c && buff != "") { v.push_back(buff); buff = ""; }
	}
	if(buff != "") v.push_back(buff);
	
	return v;
}


bool has_illegal_char(string s){
  string illegalChars = ILLEGAL_CHARS;
  string::iterator it;
  for (it = s.begin() ; it < s.end() ; ++it){
    bool found = illegalChars.find(*it) != string::npos;
    if(found){
        return true;
    }
  }
  return false;
}
