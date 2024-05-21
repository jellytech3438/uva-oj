#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<char, vector<bool>> key = {
    {'c', {false, true, true, true, false, false, true, true, true, true}},
    {'d', {false, true, true, true, false, false, true, true, true, false}},
    {'e', {false, true, true, true, false, false, true, true, false, false}},
    {'f', {false, true, true, true, false, false, true, false, false, false}},
    {'g', {false, true, true, true, false, false, false, false, false, false}},
    {'a', {false, true, true, false, false, false, false, false, false, false}},
    {'a', {false, true, true, false, false, false, false, false, false, false}},
    {'b',
     {false, true, false, false, false, false, false, false, false, false}},
    {'C',
     {false, false, true, false, false, false, false, false, false, false}},
    {'D', {true, true, true, true, false, false, true, true, true, false}},
    {'E', {true, true, true, true, false, false, true, true, false, false}},
    {'F', {true, true, true, true, false, false, true, false, false, false}},
    {'G', {true, true, true, true, false, false, false, false, false, false}},
    {'A', {true, true, true, false, false, false, false, false, false, false}},
    {'B', {true, true, false, false, false, false, false, false, false, false}},
};

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  cin.ignore(256, '\n');
  for (int i = 0; i < n; i++) {
    vector<bool> press = vector<bool>(10, false);
    vector<int> pt = vector<int>(10, 0);
    string line;
    getline(cin, line);

    for (char s : line) {
      for (int j = 0; j < key[s].size(); j++) {
        if (press[j] != key[s][j]) {
          if (press[j] == false) {
            pt[j]++;
          }
          press[j] = key[s][j];
        }
      }
    }

    cout << pt[0];
    for (int j = 1; j < 10; j++) {
      cout << " " << pt[j];
    }
    cout << endl;
  }
  return 0;
}
