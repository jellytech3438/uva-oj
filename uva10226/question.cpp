#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  cin.ignore(256, '\n');

  map<string, int> answer;
  string line;
  bool blank = false;
  bool firstblank = true;
  int total = 0;

  // for (int i = 0; i < 3; i++) {
  //   vector<string> temp;
  //   while (getline(cin, line), line != "$") {
  //     temp.push_back(line);
  //   }
  //
  //   // do something to temp
  //
  //   temp.clear();
  //   temp = vector<string>(3, "test");
  //   vector<vector<string>> t2(3, vector<string>(3, "test"));
  // }

  while (getline(cin, line)) {
    if (line == "") {
      blank = true;
    }
    if (blank) {
      for (auto &p : answer) {
        cout << p.first << " " << setprecision(4) << fixed
             << (double)p.second / (double)total * 100 << endl;
      }
      if (firstblank) {
        firstblank = false;
      } else {
        cout << endl;
      }

      answer.clear();
      blank = false;
      total = 0;
      continue;
    }

    answer[line]++;
    total++;
  }

  for (auto &p : answer) {
    cout << p.first << " " << setprecision(4) << fixed
         << (double)p.second / (double)total * 100 << endl;
  }
  return 0;
}
