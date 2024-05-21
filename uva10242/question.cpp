#include <iomanip>
#include <iostream>
#include <set>
#include <utility>

using namespace std;

int main(int argc, char *argv[]) {
  double ps[8];
  set<pair<double, double>> pt;
  while (cin >> ps[0] >> ps[1] >> ps[2] >> ps[3] >> ps[4] >> ps[5] >> ps[6] >>
         ps[7]) {
    pair<double, double> dup;

    for (int i = 0; i < 4; i++) {
      if (pt.find({ps[2 * i], ps[2 * i + 1]}) == pt.end()) {
        pt.insert({ps[2 * i], ps[2 * i + 1]});
      } else {
        dup = {ps[2 * i], ps[2 * i + 1]};
      }
    }

    double x = 0, y = 0;
    for (auto it = pt.begin(); it != pt.end(); it++) {
      // cout << "t: " << it->first << " " << it->second << endl;
      if (it->first == dup.first && it->second == dup.second) {
        x -= it->first;
        y -= it->second;
      } else {
        x += it->first;
        y += it->second;
      }
    }

    cout << setprecision(3) << fixed << x << " " << y << endl;
    pt.clear();
  }
  return 0;
}
