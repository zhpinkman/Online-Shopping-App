#include "handlers.hpp"

using namespace std;

Response *RandomNumberHandler::callback(Request *req) {
  Response *res = new Response;
  res->setHeader("Content-Type", "text/html");
  string body;
  body += "<!DOCTYPE html>";
  body += "<html>";
  body += "<body style=\"text-align: center;\">";
  body += "<h1>AP HTTP</h1>";
  body += "<p>";
  body += "a random number in [1, 10] is: ";
  body += to_string(rand() % 10 + 1);
  body += "</p>";
  body += "<p>";
  body += "SeddionId: ";
  body += req->getSessionId();
  body += "</p>";
  body += "</body>";
  body += "</html>";
  res->setBody(body);
  return res;
}

Response *LoginHandler::callback(Request *req) {
  string username = req->getBodyParam("username");
  string password = req->getBodyParam("password");
  if (username == "root")
    throw Server::Exception("Remote root access has been disabled.");
  cout << "username: " << username << ",\tpassword: " << password << endl;
  Response *res = Response::redirect("/home");
  res->setSessionId("SID");
  return res;
}

Response *UploadHandler::callback(Request *req) {
  string name = req->getBodyParam("file_name");
  string file = req->getBodyParam("file");
  cout << name << " (" << file.size() << "B):\n" << file << endl;
  Response *res = Response::redirect("/");
  return res;
}

ColorHandler::ColorHandler(string filePath) : TemplateHandler(filePath) {}

map<string, string> ColorHandler::handle(Request *req) {
  map<string, string> context;
  string newName = "I am " + req->getQueryParam("name");
  context["name"] = newName;
  context["color"] = req->getQueryParam("color");
  return context;
}

HomeHandler::HomeHandler(string filePath) : TemplateHandler(filePath) {}

map<string, string> HomeHandler::handle(Request *req) {
  map<string, string> context;
  string newName = "Mohsen";
  context["name"] = newName;
  context["1"] = "1 Bugatti Chiron SuperSoprt 2016 AT";
  context["2"] = "2 Lamborghini Centenario 2016 AT";
  context["3"] = "3 Hummer H2 2009 AT";
  context["4"] = "4 Mercedes Benz SLS AMG 2014 AT";
  context["5"] = "5 Rolls Royce Ghost Series II 2016 AT";
  context["6"] = "6 Volkswagen Beetle 2016 AT";
  context["7"] = "7 Hyundai Sonata LF 2017 Hybrid AT - A";
  context["8"] = "8 IKCO Samand LX-EF7 1397 MT";

  return context;
}
