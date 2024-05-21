#include <iostream>
#include <string>
#include <utility>

using namespace std;

int f(int start, int end) {
  int cnt = 0;
  for (int i = start; i <= end; i++) {
    cnt += i;
  }
  return cnt;
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int l[4];
    int step = 0;
    for (int j = 0; j < 4; j++) {
      cin >> l[j];
    }

    pair<int, int> start = {l[0], l[1]};
    pair<int, int> end = {l[2], l[3]};

    int ss;
    if (start.first == 0 && start.second == 0) {
      ss = 0;
    } else if (start.first == 0 && start.second != 0) {
      ss = f(0, start.second);
    } else if (start.first != 0 && start.second == 0) {
      ss = f(2, 1 + start.first);
    } else {
      ss = f(0, start.second) +
           f(start.second + 2, start.second + 1 + start.first);
    }
    int es;
    if (end.first == 0 && end.second == 0) {
      es = 0;
    } else if (end.first == 0 && end.second != 0) {
      es = f(0, end.second);
    } else if (end.first != 0 && end.second == 0) {
      es = f(2, 1 + end.first);
    } else {
      es = f(0, end.second) + f(end.second + 2, end.second + 1 + end.first);
    }
    step = es - ss;

    // while (true) {
    //   if (start == end) {
    //     break;
    //   }
    //
    //   if (start.second == 0) {
    //     start.second = start.first + 1;
    //     start.first = 0;
    //     step++;
    //     continue;
    //   }
    //
    //   start.first++;
    //   start.second--;
    //   step++;
    // }

    cout << "Case " << i + 1 << ": " << step << endl;
  }
  return 0;
}
