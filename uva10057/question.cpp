#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int b;
  while (cin >> b) {
    vector<int> ns;
    for (int i = 0; i < b; i++) {
      int temp;
      cin >> temp;
      ns.push_back(temp);
    }

    sort(ns.begin(), ns.end());

    int mina;
    set<int> possibility;

    if (ns.size() % 2 == 0) {
      int mid = ns.size() / 2 - 1;
      mina = ns[mid];
      for (int j = ns[mid]; j <= ns[mid + 1]; j++) {
        possibility.insert(j);
      }
    } else {
      int mid = ns.size() / 2;
      mina = ns[mid];
      possibility.insert(mina);
    }

    int cnt = 0;
    for (int j = 0; j < ns.size(); j++) {
      if (possibility.find(ns[j]) != possibility.end()) {
        cnt++;
      }
    }

    cout << mina << " " << cnt << " " << possibility.size() << endl;
  }
  return 0;
}
