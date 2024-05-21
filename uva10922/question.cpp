#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  string line;
  while (getline(cin, line), line != "0") {
    int temp = 0;
    while (temp) {
      for (int i = 0; i < line.length(); i++) {
        temp += (line[i] - '0');
      }
    }
  }
  return 0;
}
