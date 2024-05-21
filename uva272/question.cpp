#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  string line;
  int cnt = 0;
  while (getline(cin, line)) {
    for (auto i : line) {
      if (i == '\"') {
        if (cnt % 2 == 1) {
          cout << "\'\'";
        } else {
          cout << "``";
        }
        cnt++;
      } else {
        cout << i;
      }
    }
    cout << endl;
  }

  return 0;
}
