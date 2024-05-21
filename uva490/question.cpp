#include <iostream>
#include <string>
using namespace std;

int maxS = 100;

int main(int argc, char *argv[]) {
  string line[maxS];
  int totalL = 0;
  while (getline(cin, line[totalL])) {
    totalL++;
  }

  int maxL = 0;
  for (string i : line) {
    if (i != "") {
      if (maxL < i.length()) {
        maxL = i.length();
      }
    }
  }

  for (int i = 0; i < maxL; i++) {
    int cnt = i;
    for (int j = totalL - 1; j >= 0; j--) {
      if (line[j].length() <= i) {
        cout << " ";
      } else {
        cout << line[j][i];
      }
    }
    cout << endl;
  }

  return 0;
}
