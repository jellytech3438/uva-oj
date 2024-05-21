#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  string line;
  int index = 1;
  while (cin >> line) {

    int l = line.length();
    if (l != 15) {
      line = string(15 - l, '0') + line;
    }

    string addexp = "";

    pair<int, int> pos[9] = {{0, 1}, {1, 2},  {3, 2},  {5, 1}, {6, 2},
                             {8, 2}, {10, 2}, {12, 1}, {13, 2}};
    string exps[9] = {"kuti", "lakh",  "hajar", "shata", "kuti",
                      "lakh", "hajar", "shata", ""};
    for (int j = 0; j < 9; j++) {
      string temp = line.substr(pos[j].first, pos[j].second);
      stringstream ss1(temp);
      int t;
      ss1 >> t;

      // cout << temp << endl;

      if (t != 0) {
        addexp += (" " + to_string(t) + " " + exps[j]);
        continue;
      }
      if (j == 4) {
        string prev = line.substr(0, pos[j].first);
        stringstream ss(prev);
        int p;
        ss >> p;

        // cout << p << endl;

        if (p == 0) {

        } else {
          addexp += (" " + exps[j]);
        }
      }
    }

    if (addexp.back() == ' ') {
      addexp.pop_back();
    }
    cout << setw(4) << index << ". " << addexp.substr(1) << endl;
    index++;

    // int pind = 0;
    // int tempcnt = 0;
    // int lcnt = 0;
    // string answer = line;
    // int insertp = line.length();
    // bool most_right = true;
    // for (int c = line.length() - 1; c >= 0; c--) {
    //   tempcnt++;
    //   lcnt++;
    //   bool fillzero = true;
    //   // cout << tempcnt << " " << c << endl;
    //   if (tempcnt == pad[pind]) {
    //     int base = c;
    //     // cout << "base: " << base << " " << c << " " << pad[pind] <<
    //     endl; for (int f = pad[pind] - 1; f >= 0; f--) {
    //       if (line[base] == '0') {
    //         // if (pind == 1) {
    //         //   cout << "erase: " << base << " " << endl;
    //         // }
    //         answer.erase(base, pad[pind]);
    //         line.erase(base, pad[pind]);
    //         // c = c - pad[pind] + 1;
    //         // cout << "c" << c << endl;
    //       } else if (line[base] == NULL) {
    //         break;
    //       } else {
    //         fillzero = false;
    //         break;
    //       }
    //     }
    //     // cout << fillzero << endl;
    //
    //     if (insertp - lcnt == 0) {
    //       break;
    //     }
    //
    //     if (most_right && fillzero) {
    //
    //     } else if (most_right && !fillzero) {
    //       answer.insert(insertp - lcnt, exp[pind]);
    //       most_right = false;
    //     } else {
    //       if (!fillzero) {
    //         answer.insert(insertp - lcnt, exp[pind]);
    //       } else {
    //         if (pind == 3)
    //           answer.insert(insertp - lcnt, exp[pind]);
    //       }
    //     }
    //
    //     if (pind == 3) {
    //       pind = 0;
    //     } else {
    //       pind++;
    //     }
    //     insertp -= lcnt;
    //     tempcnt = 0;
    //     lcnt = 0;
    //   }
    // }
    // cout << setw(4) << index << ". " << answer << endl;
    // index++;
  }
  return 0;
}
