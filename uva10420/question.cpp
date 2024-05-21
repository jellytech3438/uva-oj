#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  cin.ignore(256, '\n');
  map<string, set<string>> list;
  map<string, int> cnt;
  for (int i = 0; i < n; i++) {
    string line;
    getline(cin, line);

    size_t t = line.find(" ");

    string country = line.substr(0, t);
    string name = line.substr(t + 1, line.length());

    list[country].insert(name);
    cnt[country]++;

    // cout << country << "=" << name << endl;
  }

  for (auto &p : cnt) {
    cout << p.first << " " << p.second << endl;
  }
  return 0;
}
