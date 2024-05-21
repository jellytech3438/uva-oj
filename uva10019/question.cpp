#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;

  int ns[n];

  for (int i = 0; i < n; i++) {
    cin >> ns[i];

    int origin = ns[i];

    int b1 = 0;
    for (int j = 0; j < 16; j++) {
      if (ns[i] % 2 == 1) {
        b1++;
      }
      ns[i] >>= 1;
    }

    ns[i] = origin;

    int b2 = 0;
    while (ns[i] != 0) {
      int temp = ns[i] % 10;
      for (int j = 0; j < 16; j++) {
        if (temp % 2 == 1) {
          b2++;
        }
        temp >>= 1;
      }
      ns[i] /= 10;
    }

    cout << b1 << " " << b2 << endl;
  }
  return 0;
}
