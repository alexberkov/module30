#include <iostream>
#include <cpr/cpr.h>

using namespace std;

int main() {
  cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"),
                             cpr::Header({{"accept", "text/html"}}));
  string html = r.text;
  int start = (int) html.find("<h1>") + 4, end = (int) html.find("</h1>");
  cout << html.substr(start, end - start) << endl;
  return 0;
}
