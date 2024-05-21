#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++) {
    int day, pp;
    cin >> day >> pp;
    int hp[pp];
    for (int j = 0; j < pp; j++) {
      cin >> hp[j];
    }

    int cnt = 0;
    for (int j = 1; j <= day; j++) {
      if (j % 7 == 0 || (j + 1) % 7 == 0) {
        continue;
      }
      bool any = false;
      for (int k = 0; k < pp; k++) {
        if (j % hp[k] == 0) {
          any = true;
          break;
        }
      }
      if (any) {
        cnt++;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
