#include <array>
#include <iostream>
#include <math.h>
#include <vector>
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
  int n, m;
  while (cin >> n >> m) {

    // int temp = gcd(n, m);
    // cout << temp << endl;
    // if (gcd(n, m) != m) {
    //   cout << "Boring!" << endl;
    //   continue;
    // }
    //
    // vector<int> s;
    // s.push_back(n);
    //
    // for (int i = 0; s[i] % m == 0; i++) {
    //   s.push_back(s[i] / m);
    // }
    //
    // cout << s[0];
    // for (int i = 1; i < s.size(); i++) {
    //   cout << " " << s[i];
    // }
    // cout << endl;
    cin.sync_with_stdio(0);
    cin.tie(0);

    vector<int> s;
    s.push_back(n);
    int index = 0;

    if (m <= 1) {
      cout << "Boring!" << endl;
      continue;
    }

    if (abs(log(n) / log(m)) - (double)((int)(log(n) / log(m))) < 0.000000001) {
    } else {
      cout << "Boring!" << endl;
      continue;
    }

    for (; s[index] % m == 0; index++) {
      s.push_back(s[index] / m);
      if (s[index] / m == 1) {
        break;
      }
    }

    if (s.back() != 1) {
      cout << "Boring!" << endl;
    } else {
      cout << s[0];
      for (int i = 1; i < s.size(); i++) {
        cout << " " << s[i];
      }
      cout << endl;
    }
  }
  return 0;
}
