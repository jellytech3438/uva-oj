#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  string line;
  int cnt = 0;
  while (getline(cin, line)) {
    map<char, int> ascii;
    for (char s : line) {
      ascii[s]++;
    }
    multimap<int, char> newmap;
    for (auto &p : ascii) {
      newmap.insert({p.second, p.first});
    }

    if (cnt != 0) {
      cout << endl;
    }

    int jump = 0;
    for (auto &p : newmap) {
      if (jump != 0) {
        jump--;
        continue;
      }
      vector<char> temp;
      for (auto k = newmap.equal_range(p.first).first;
           k != newmap.equal_range(p.first).second; k++) {
        temp.push_back(k->second);
        // cout << (unsigned int)k->second << " " << k->first << endl;
      }
      for (int it = temp.size() - 1; it >= 0; it--) {
        cout << (unsigned int)temp[it] << " " << p.first << endl;
      }
      // cout << "size:" << temp.size() << endl;
      jump = temp.size() - 1 >= 0 ? temp.size() - 1 : 0;
    }
    cnt++;
  }
  return 0;
}
