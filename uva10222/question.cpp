#include <cctype>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  string line;
  getline(cin, line);

  map<char, char> k = {
      {'e', 'q'},  {'r', 'w'}, {'t', 'e'},  {'y', 'r'}, {'u', 't'}, {'i', 'y'},
      {'o', 'u'},  {'p', 'i'}, {'[', 'o'},  {']', 'p'}, {'d', 'a'}, {'f', 's'},
      {'g', 'd'},  {'h', 'f'}, {'j', 'g'},  {'k', 'h'}, {'l', 'j'}, {';', 'k'},
      {'\'', 'l'}, {'c', 'z'}, {'v', 'x'},  {'b', 'c'}, {'n', 'v'}, {'m', 'b'},
      {',', 'n'},  {'.', 'm'}, {'/', ','},  {'2', '`'}, {'3', '1'}, {'4', '2'},
      {'5', '3'},  {'6', '4'}, {'7', '5'},  {'8', '6'}, {'9', '7'}, {'0', '8'},
      {'-', '9'},  {'=', '0'}, {'\\', '['}, {' ', ' '}};

  for (int i = 0; i < line.length(); i++) {
    if (line[i] == '\\') {
      continue;
    }
    cout << k[tolower(line[i])];
  }

  return 0;
}
