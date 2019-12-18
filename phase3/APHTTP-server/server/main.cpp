#include "../utils/utilities.hpp"
#include "server.hpp"
#include "jeekjeek/jeekjeek.hpp"
#include "jeekjeek/user_session.hpp"
#include "handlers.hpp"
#include <stdlib.h>
#include <time.h>  
#include <string>
#include <iostream>

using namespace std;

class ShowPage : public RequestHandler {
  string filePath;

public:
  ShowPage(string _filePath) { filePath = _filePath; }
  Response *callback(Request *req) {
    Response *res = new Response;
    res->setHeader("Content-Type", "text/html; charset=utf-8");
    string body = readFile(filePath.c_str());
    res->setBody(readFile(filePath.c_str()));
    return res;
  }
};

class ShowImage : public RequestHandler {
  string filePath;
public:
  ShowImage(string _filePath) { filePath = _filePath; }
  Response *callback(Request *req) {
    Response *res = new Response;
    res->setHeader("Content-Type", "image/png");
    string body = readFile(filePath.c_str());
    res->setBody(body);
    return res;
  }
};




int main(int argc, char **argv) {
  Jeekjeek* jeekjeek = new Jeekjeek;
  User_sessions* sessions = new User_sessions;

  try{
  jeekjeek->signup("durov", "Pavel Durov", "durov");
  jeekjeek->login("durov", "durov");
  jeekjeek->make_account_official("durov");
  vector<string> s;
  s.push_back("Telegram");
  s.push_back("digitalresistance");
  jeekjeek->jeek("Power outage at a @telegram server cluster causing issues in Europe. Working to fix it from our side, but a lot depends on when the datacenter provider puts the power equipment in order.", s, s);
  jeekjeek->jeek("For 7 days Russia has been trying to ban Telegram on its territory – with no luck so far. We were able to survive under the most aggressive attempt of internet censorship in Russian history with almost 18 million IP addresses blocked.", s, s);
  jeekjeek->jeek("Thank you @Apple and @tim_cook for letting us deliver the latest version of @telegram to millions of users, despite the recent setbacks.", s, s);
  
  jeekjeek->signup("mohsenfayyaz", "Mohsen Fayyaz", "test1234");
  jeekjeek->login("mohsenfayyaz", "test1234");
  vector<string> a;
  a.push_back("Mohsenfayyaz.ir");
  a.push_back("JeekJeek");
  jeekjeek->jeek("Hi <br> Welcome to jeekjeek <br> Don't forget to check out mohsenfayyaz.ir <br> thanks", a, a);
  jeekjeek->make_account_official("mohsenfayyaz");
  jeekjeek->logout();
  
  }catch(const char* err){
    cerr << err;
  }

  try {
    Server server(argc > 1 ? atoi(argv[1]) : 5000);

    server.get("/", new ShowPage("htmlFiles/home/index.html"));
    server.get("/login_page", new ShowPage("htmlFiles/login/index.html"));
    server.post("/login", new LoginHandler(jeekjeek, sessions));

    server.get("/signup_page", new ShowPage("htmlFiles/signup/index.html"));
    server.post("/signup", new SignupHandler(jeekjeek));

    server.get("/home_page", new ShowPage("htmlFiles/home/index.html"));
    
    server.post("/search", new SearchHandler(jeekjeek, sessions));
    server.post("/get_username", new GetUsernameHandler(sessions));
    server.post("/get_display_name", new GetDisplaynameHandler(jeekjeek, sessions));
    server.post("/rejeek", new RejeekHandler(jeekjeek, sessions));
    server.post("/like", new LikeHandler(jeekjeek, sessions));
    server.post("/num_of_likes", new NumOfLikesHandler(jeekjeek));
    server.post("/logout", new LogoutHandler(sessions));
    server.post("/get_notifications", new GetNotificationsHandler(jeekjeek, sessions));
    server.post("/get_num_of_notifications", new GetNumOfNotificationsHandler(jeekjeek, sessions));
    server.post("/new_jeek", new NewJeekHandler(jeekjeek, sessions));


    server.run();
  } catch (Server::Exception e) {
    cout << e.getMessage() << endl;
  }
}


