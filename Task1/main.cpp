#include <iostream>
#include <cpr/cpr.h>

using namespace std;

int main() {
  string request, url = "http://httpbin.org/";
  while (request != "ext") {
    cout << "Enter request: ";
    cin >> request;
    cpr::Response r;
    if (request == "get") r = cpr::Get(cpr::Url(url + request));
    else if (request == "post") r = cpr::Post(cpr::Url(url + request));
    else if (request == "put") r = cpr::Put(cpr::Url(url + request));
    else if (request == "delete") r = cpr::Delete(cpr::Url(url + request));
    else if (request == "patch") r = cpr::Patch(cpr::Url(url + request));
    else if (request == "ext") break;
    else cout << "Incorrect request!" << endl;
    cout << r.text << endl;
  }
  cout << "Goodbye!";
  return 0;
}
