#include <cctype>
#include <ios>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

  string line;
  while (getline(cin, line)) {
    int n = 0;
    if (isdigit(line[0])) {
      // cout << line << endl;
      for (char s : line) {
        n = n * 10 + (s - '0');
      }
      // n = stol(line.c_str());
      if (n + 1 < 2 || n + 1 > 63) {
        cout << "such number is impossinle!" << endl;
      } else {
        cout << (unsigned int)n + 1 << endl;
      }
    } else {
      // cout << line << endl;
      int b;
      for (int i = 0; i < line.length(); i++) {
        if (isupper(line[i])) {
          // A = 10
          b = (unsigned int)line[i] - 55;
        } else {
          // a = 37
          b = (unsigned int)line[i] - 60;
        }
      }
      if (b + 1 < 2 || b + 1 > 63) {
        cout << "such number is impossinle!" << endl;
      } else {
        cout << (unsigned int)b + 1 << endl;
      }
    }
  }

  return 0;
}
