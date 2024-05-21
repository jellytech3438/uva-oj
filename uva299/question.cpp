#include <iostream>
using namespace std;

int sort(int c[], int l) {
  int cnt = 0;
  for (int i = 0; i < l - 1; i++) {
    int tempind = i;
    int min = c[i];
    for (int j = i + 1; j < l; j++) {
      if (min > c[j]) {
        tempind = j;
        min = c[j];
      }
    }

    if (tempind == i) {
      continue;
    }

    // swap
    for (int j = tempind; j > i; j--) {
      int temp = c[j];
      c[j] = c[j - 1];
      c[j - 1] = temp;
      cnt++;
    }
  }
  return cnt;
}

int main(int argc, char *argv[]) {
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    int length;
    cin >> length;
    int carragies[length];
    for (int j = 0; j < length; j++) {
      cin >> carragies[j];
    }
    cout << "Optimal train swapping takes " << sort(carragies, length)
         << " swaps." << endl;
  }
  return 0;
}
