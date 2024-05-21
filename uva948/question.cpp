#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maxL = 50;

int main(int argc, char *argv[]) {
  int ns;
  vector<unsigned long long int> fib = {0, 1};
  for (int j = 2; j <= maxL; j++) {
    fib.push_back(fib[j - 1] + fib[j - 2]);
  }
  // remove 0 and 1
  fib.erase(fib.begin());
  fib.erase(fib.begin());

  cin >> ns;
  for (int i = 0; i < ns; i++) {
    int n;
    cin >> n;

    // lower bound of n
    int base = n;
    int index = lower_bound(fib.begin(), fib.end(), n) - fib.begin();
    string ans = string(maxL, '0');

    while (base != 0) {
      // cout << "base: " << base << endl;
      if (fib[index] == base) {
        base -= fib[index];
        ans[index] = '1';
      } else {
        base -= fib[index - 1];
        ans[index - 1] = '1';
      }

      index = lower_bound(fib.begin(), fib.end(), base) - fib.begin();
    }

    ans = ans.substr(0, ans.rfind('1') + 1);
    reverse(ans.begin(), ans.end());

    // if (fib[index] == n) {
    //   for (int k = 0; k < index; k++) {
    //     answer.push_back('0');
    //   }
    // } else {
    //   int temp = n;
    //   while (true) {
    //     temp = temp - fib[index - 1];
    //     int pind = index;
    //     index = lower_bound(fib.begin(), fib.end(), temp) - fib.begin();
    //     // cout << pind << " " << index << endl;
    //     if (fib[index] == temp) {
    //       for (int l = pind - 1; l > index + 1; l--) {
    //         answer.push_back('0');
    //       }
    //       answer.push_back('1');
    //       for (int l = index; l > 0; l--) {
    //         answer.push_back('0');
    //       }
    //       break;
    //     } else {
    //       // temp -= fib[index - 1];
    //       for (int l = pind - 1; l > index + 1; l--) {
    //         answer.push_back('0');
    //       }
    //     }
    //   }
    // }
    cout << n << " = " << ans << " (fib)" << endl;
  }

  return 0;
}
