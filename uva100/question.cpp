#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(true);
  cin.tie(0);

  map<unsigned int, int> cycle;
  cycle[1] = 1;
  unsigned int lowerb, upperb;
  while (cin >> lowerb >> upperb) {
    int max = 0;
    for (unsigned int i = min(lowerb, upperb); i <= std::max(lowerb, upperb);
         i++) {
      if (cycle[i]) {
        if (max < cycle[i]) {
          max = cycle[i];
        }
        continue;
      }
      unsigned int temp = i;
      int cnt = 0;
      while (temp != 1) {
        if (temp % 2 == 1) {
          temp = 3 * temp + 1;
        } else {
          temp = temp / 2;
        }
        cnt++;
        if (cycle[temp]) {
          cnt += cycle[temp];
          cycle[i] = cnt;
          if (max < cycle[i]) {
            max = cycle[i];
          }
          break;
        }
      }
    }

    cout << lowerb << " " << upperb << " " << max << endl;
  }

  return 0;
}
