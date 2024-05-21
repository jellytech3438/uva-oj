#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  string a, b;
  while (getline(cin, a), getline(cin, b)) {
    // cout << a << b << endl;
    vector<char> dp;
    for (int i = 0; i < a.length(); i++) {
      size_t p = b.find(a[i]);
      if (p != string::npos) {
        dp.push_back(a[i]);
        // cout << "p: " << p << endl;
        b.erase(p, 1);
      }
    }
    // cout << a << " " << b << endl;
    sort(dp.begin(), dp.end());
    for (char d : dp) {
      cout << d;
    }
    cout << endl;
  }
  return 0;
}
