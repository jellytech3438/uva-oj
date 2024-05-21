#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

void addMine(char map, int x, int y, int maxx, int maxy) {}

int main(int argc, char *argv[]) {
  int n, m;
  int f = 1;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) {
      break;
    }
    char map[n][m];
    vector<pair<int, int>> mine;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> map[i][j];
        if (map[i][j] == '*') {
          mine.push_back({i, j});
        }
      }
    }

    char printmap[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        printmap[i][j] = '0';
      }
    }

    for (int i = 0; i < mine.size(); i++) {
      int x = mine[i].first, y = mine[i].second;
      // cout << x << " " << y << endl;
      // addMine(&printmap, x, y, n, m);

      printmap[x][y] = '*';
      if (x - 1 >= 0 && y - 1 >= 0) {
        if (printmap[x - 1][y - 1] == '0') {
          printmap[x - 1][y - 1] = '1';
        } else {
          if (printmap[x - 1][y - 1] != '*') {
            printmap[x - 1][y - 1] = printmap[x - 1][y - 1] + 1;
          }
        }
      }
      if (x + 1 <= n && y - 1 >= 0) {
        if (printmap[x + 1][y - 1] == '0') {
          printmap[x + 1][y - 1] = '1';
        } else {
          if (printmap[x + 1][y - 1] != '*') {
            printmap[x + 1][y - 1] = printmap[x + 1][y - 1] + 1;
          }
        }
      }
      if (x - 1 >= 0 && y + 1 < m) {
        if (printmap[x - 1][y + 1] == '0') {
          printmap[x - 1][y + 1] = '1';
        } else {
          if (printmap[x - 1][y + 1] != '*') {
            printmap[x - 1][y + 1] = printmap[x - 1][y + 1] + 1;
          }
        }
      }
      if (x + 1 < n && y + 1 < m) {
        if (printmap[x + 1][y + 1] == '0') {
          printmap[x + 1][y + 1] = '1';
        } else {
          if (printmap[x + 1][y + 1] != '*') {
            printmap[x + 1][y + 1] = printmap[x + 1][y + 1] + 1;
          }
        }
      }
      if (x - 1 >= 0) {
        if (printmap[x - 1][y] == '0') {
          printmap[x - 1][y] = '1';
        } else {
          if (printmap[x - 1][y] != '*') {
            printmap[x - 1][y] = printmap[x - 1][y] + 1;
          }
        }
      }
      if (x + 1 < n) {
        if (printmap[x + 1][y] == '0') {
          printmap[x + 1][y] = '1';
        } else {
          if (printmap[x + 1][y] != '*') {
            printmap[x + 1][y] = printmap[x + 1][y] + 1;
          }
        }
      }
      if (y - 1 >= 0) {
        if (printmap[x][y - 1] == '0') {
          printmap[x][y - 1] = '1';
        } else {
          if (printmap[x][y - 1] != '*') {
            printmap[x][y - 1] = printmap[x][y - 1] + 1;
          }
        }
      }
      if (y + 1 < m) {
        if (printmap[x][y + 1] == '0') {
          printmap[x][y + 1] = '1';
        } else {
          if (printmap[x][y + 1] != '*') {
            printmap[x][y + 1] = printmap[x][y + 1] + 1;
          }
        }
      }
    }

    if (f != 1) {
      cout << endl;
    }

    cout << "Field #" << f << ":" << endl;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << printmap[i][j];
      }
      cout << endl;
    }
    f++;
  }
  return 0;
}
