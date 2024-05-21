#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  int a, b;
  while (cin >> a >> b) {
    if (a == 0 && b == 0) {
      break;
    }

    int carry = 0;
    int ccnt = 0;
    string na = to_string(a);
    string nb = to_string(b);

    reverse(na.begin(), na.end());
    reverse(nb.begin(), nb.end());

    for (int i = 0; i < max(na.length(), nb.length()); i++) {
      int sa, sb;
      if (na.length() < i + 1) {
        sa = 0;
      } else {
        sa = na[i] - '0';
      }
      if (nb.length() < i + 1) {
        sb = 0;
      } else {
        sb = nb[i] - '0';
      }
      if (sa + sb + carry >= 10) {
        carry = 1;
        ccnt++;
      } else {
        carry = 0;
      }
    }

    if (ccnt == 0) {
      cout << "No carry operation." << endl;
    } else if (ccnt == 1) {
      cout << ccnt << " carry operation." << endl;
    } else {
      cout << ccnt << " carry operations." << endl;
    }
  }
  return 0;
}
