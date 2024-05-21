#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum direction { N, E, S, W };

/*
 * X 0 X
 * 1 2 3
 * X 4 X
 */

int main(int argc, char *argv[]) {
  int n;
  while (cin >> n, n != 0) {
    cin.ignore(256, '\n');
    // cout << "n:" << n << endl;
    // vector<string> d;

    vector<int> dice = {2, 3, 1, 4, 5};
    for (int i = 0; i < n; i++) {
      string line;
      getline(cin, line);
      // d.push_back(line);
      if (line == "north") {
        // 0 2 4
        for (int j = 0; j < 4; j += 2) {
          dice[j] = dice[j + 2];
        }
        dice[4] = 7 - dice[0];
      } else if (line == "east") {
        // 1 2 3
        for (int j = 3; j > 1; j--) {
          dice[j] = dice[j - 1];
        }
        dice[1] = 7 - dice[3];
      } else if (line == "west") {
        // 1 2 3
        for (int j = 1; j < 3; j++) {
          dice[j] = dice[j + 1];
        }
        dice[3] = 7 - dice[1];
      } else if (line == "south") {
        // 0 2 4
        for (int j = 4; j > 0; j -= 2) {
          dice[j] = dice[j - 2];
        }
        dice[0] = 7 - dice[4];
      }
      // cout << "step:";
      // for (int k = 0; k < 5; k++) {
      //   cout << " " << dice[k];
      // }
      // cout << endl;
    }
    cout << dice[2] << endl;
  }
  return 0;
}
