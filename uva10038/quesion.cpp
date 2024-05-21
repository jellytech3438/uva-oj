#include <cstdlib>
#include <iostream>
#include <map>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  while (cin >> n) {
    int ns[n];

    int prev;
    bool isjelly = true;
    for (int i = 0; i < n; i++) {
      cin >> ns[i];
    }

    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        prev = ns[i];
      } else {
        int temp = abs(ns[i] - prev);
        if (temp >= 1 && temp <= n - 1 && cnt[temp] == 0) {
          cnt[temp]++;
        } else {
          isjelly = false;
          break;
        }
        prev = ns[i];
      }
    }

    if (isjelly) {
      cout << "Jolly" << endl;
    } else {
      cout << "Not jolly" << endl;
    }
  }
  return 0;
}
