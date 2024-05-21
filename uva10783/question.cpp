#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int tc;
  while (cin >> tc) {
    int a, b;
    for (int i = 0; i < tc; i++) {
      cin >> a >> b;

      int sum = 0;
      for (int j = min(a, b); j <= max(a, b); j++) {
        if (j % 2 == 1) {
          sum += j;
        }
      }

      cout << "Case " << i + 1 << ": " << sum << endl;
    }
  }
  return 0;
}
