#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  long long int x;

  while (cin >> x) {
    cin.ignore(265, '\n');
    string line;
    getline(cin, line);
    stringstream ss(line);
    string tok;

    vector<string> toks;

    while (getline(ss, tok, ' ')) {
      toks.push_back(tok);
    }

    // cout << "toks:";
    // for (int i = 0; i < toks.size() - 1; i++) {
    //   cout << toks[i] << " ";
    // }
    // cout << endl;

    int n = toks.size() - 1;
    // cout << "n" << n << endl;
    long long int ans = 0;
    for (int i = 0; i < toks.size() - 1; i++) {
      stringstream ss(toks[i]);
      long long temp;
      ss >> temp;

      // cout << "temp: " << temp << endl;

      ans += temp * (n - i) * powl(x, (n - i - 1));
    }

    cout << ans << endl;
  }
  return 0;
}
