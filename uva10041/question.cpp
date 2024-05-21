#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int c;
  cin >> c;
  for (int i = 0; i < c; i++) {
    int n;
    cin >> n;
    vector<int> ns;
    for (int j = 0; j < n; j++) {
      int temp;
      cin >> temp;
      ns.push_back(temp);
    }

    int sum = 0;
    sort(ns.begin(), ns.end());

    int median = ns[ns.size() / 2];

    for (int i = 0; i < ns.size(); i++) {
      sum += abs(ns[i] - median);
    }

    cout << sum << endl;
  }
  return 0;
}
