#include <iomanip>
#include <ios>
#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char *argv[]) {
  cout.setf(ios::fixed);
  int c;
  cin >> c;
  for (int i = 0; i < c; i++) {
    int player, d;
    float p;
    cin >> player >> p >> d;

    float answer = p;
    int base = (d - 1) % player;
    float cof = 0;
    for (int j = 0; j < 50; j++) {
      cof += pow((1 - p), base + player * j);
    }
    // answer *= p;
    answer *= cof;
    cout << setprecision(4) << answer << endl;
  }
  return 0;
}
