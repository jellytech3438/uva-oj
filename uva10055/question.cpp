#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
  unsigned long long int a, b;
  while (cin >> a >> b) {
    if (a > b) {
      cout << (a - b) << endl;
    } else {
      cout << (b - a) << endl;
    }
  }
  return 0;
}
