#include <iostream>
#include <map>

using namespace std;

map<int, bool> m;
bool isprime(int a) {
  if (m.find(a) != m.end()) {
    return m.find(a)->second;
  }
  for (int i = 2; i < a; i++) {
    if (a % i == 0) {
      m.insert({a, false});
      return false;
    }
  }
  m.insert({a, true});
  return true;
}

int main(int argc, char *argv[]) {
  int n;
  while (cin >> n) {
    if (isprime(n)) {
      int temp = n;
      int newn = 0;
      while (temp != 0) {
        newn = newn * 10 + (temp % 10);
        temp /= 10;
      }
      if (newn == n) {
        cout << n << " is prime." << endl;
        continue;
      }
      if (isprime(newn)) {
        cout << n << " is emirp." << endl;
      } else {
        cout << n << " is prime." << endl;
      }
    } else {
      cout << n << " is not prime." << endl;
    }
  }
  return 0;
}
