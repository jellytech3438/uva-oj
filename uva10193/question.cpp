#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int gcd(int a, int b) {
  if (a > b) {
    swap(a, b);
  }
  if (a == 0) {
    return b;
  }
  return gcd(a, b - a);
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  cin.ignore(256, '\n');
  for (int i = 0; i < n; i++) {
    string b1, b2;
    getline(cin, b1);
    getline(cin, b2);
    int i1 = 0;
    for (int j = 0; j < b1.length(); j++) {
      if (b1[j] == '1') {
        i1 += pow(2, b1.length() - j - 1);
      }
    }

    int i2 = 0;
    for (int j = 0; j < b2.length(); j++) {
      if (b2[j] == '1') {
        i2 += pow(2, b2.length() - j - 1);
      }
    }

    // cout << i1 << " " << i2 << endl;

    if (gcd(i1, i2) == 1) {
      cout << "Pair #" << i + 1 << ": "
           << "Love is not all you need!" << endl;
    } else {
      cout << "Pair #" << i + 1 << ": "
           << "All you need is love!" << endl;
    }

    // cout << i1 << " " << i2 << endl;
    //
    // cout << "Pair #" << i + 1 << ": "
    //      << "Love is not all you need!" << endl;
    // cout << "Pair #" << i + 1 << ": "
    //      << "All you need is love!" << endl;
  }
  return 0;
}
