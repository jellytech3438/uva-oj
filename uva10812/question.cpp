#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    double s, d;
    cin >> s >> d;
    if (d > s) {
      cout << "impossible" << endl;
      continue;
    }
    int higher = (s + d) / 2;
    int lower = (s - d) / 2;
    if (higher + lower == d && higher - lower == s && higher >= lower &&
        lower >= 0 && higher >= 0) {
      cout << higher << " " << lower << endl;
    } else {
      cout << "impossible" << endl;
    }
  }
  return 0;
}
