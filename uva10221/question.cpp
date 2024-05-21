#include <iomanip>
#include <ios>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

double r = 6440;

int main(int argc, char *argv[]) {
  int s, a;
  string line;
  while (cin >> s >> a >> line) {
    // cout << s << " " << a << " " << line << endl;

    double arc, chrod;
    if (line == "deg") {
      while (s >= 360) {
        s -= 360;
      }
      while (a >= 360) {
        a -= 360;
      }

      cout.precision(6);

      cout << fixed << 2 * 3.14 * r * (double)(abs(a - s)) << " " << fixed
           << 2 * r * sin(abs(a - s) / 2) << endl;

    } else if (line == "min") {
    }
  }
  return 0;
}
