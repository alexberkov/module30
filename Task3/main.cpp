#include <iostream>
#include <vector>
#include <cpr/cpr.h>

using namespace std;

int main() {
  string query;
  vector<string> keys, values;
  cpr::Response r;
  while (true) {
    cout << "Enter 'key:value' pair or method: ";
    cin >> query;
    if (query == "post" || query == "get") break;
    else {
      int pos = (int) query.find(':');
      keys.push_back(query.substr(0, pos));
      values.push_back(query.substr(pos + 1));
    }
  }
  string request = query;
  if (request == "get") {
    string args;
    for (int i = 0; i < keys.size(); i++) {
      if (i == 0) args += "?";
      args += (keys[i] + "=" + values[i]);
      if (i != keys.size() - 1) args += "&";
    }
    r = cpr::Get(cpr::Url("http://httpbin.org/get" + args));
  } else if (!keys.empty()) {
    vector<cpr::Pair> form;
    form.reserve(keys.size());
    for (int i = 0; i < keys.size(); i++) form.emplace_back(keys[i].c_str(), values[i].c_str());
    r = cpr::Post(cpr::Url("http://httpbin.org/post"), cpr::Payload({form.begin(), form.end()}));
  } else {
    r = cpr::Post(cpr::Url("http://httpbin.org/post"));
  }
  cout << r.text;
  return 0;
}
