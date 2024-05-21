#include <cctype>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  map<char, int> aphacnt;
  cin >> n;
  cin.ignore(256, '\n');
  for (int i = 0; i < n; i++) {
    string line;
    getline(cin, line);
    for (char s : line) {
      if (isalpha(s)) {
        aphacnt[toupper(s)]++;
      }
    }
  }

  multimap<int, char> newmap;
  for (auto &i : aphacnt) {
    newmap.insert({i.second, i.first});
  }

  set<int> numread;
  for (auto i = newmap.rbegin(); i != newmap.rend(); i++) {
    if (numread.find(i->first) != numread.end()) {
      continue;
    }
    for (auto j = newmap.equal_range(i->first).first;
         j != newmap.equal_range(i->first).second; j++) {
      cout << j->second << " " << j->first << endl;
    }
    numread.insert(i->first);
  }
  return 0;
}
