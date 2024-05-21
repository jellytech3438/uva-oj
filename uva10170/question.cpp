#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  unsigned long long int s, d;
  while (cin >> s >> d) {
    unsigned long long int cnt = 0;
    unsigned long long int acc = s;
    while (cnt < d) {
      cnt += acc;

      if (cnt >= d) {
        cout << acc << endl;
        break;
      }

      acc += 1;
    }
  }
  return 0;
}
