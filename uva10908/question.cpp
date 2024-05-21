#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int tc;
  cin >> tc;
  cin.ignore(256, '\n');
  for (int i = 0; i < tc; i++) {
    int m, n, q;
    cin >> m >> n >> q;
    cin.ignore(256, '\n');
    char map[m][n];
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < n; k++) {
        cin >> map[j][k];
      }
      cin.ignore(256, '\n');
    }
    vector<pair<int, int>> p;
    for (int j = 0; j < q; j++) {
      int x, y;
      cin >> x >> y;
      p.push_back({x, y});
    }

    cout << m << " " << n << " " << q << endl;
    for (int j = 0; j < p.size(); j++) {
      int x = p[j].first;
      int y = p[j].second;
      char symbol = map[x][y];
      int w = min(min(x - 0, m - x), min(y - 0, n - y));
      int tw = w;
      // cout << "tw: " << tw << endl;
      for (; tw >= 0; tw--) {
        for (int k = x - tw; k < x + tw; k++) {
          for (int l = y - tw; l < y + tw; l++) {
            if (map[k][l] != symbol) {
              goto out;
            }
          }
        }
        cout << 2 * tw + 1 << endl;
        break;

      out:
        continue;
      }
    }
  }
  return 0;
}
