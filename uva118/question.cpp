#include <iostream>
#include <set>
#include <string>
#include <tuple>
using namespace std;

set<tuple<int, int>> scene;

enum direction { N = 0, E, S, W };
struct robot {
  int posx, posy;
  enum direction d;
  robot(int x, int y, char dir) {
    posx = x;
    posy = y;
    if (dir == 'N') {
      d = N;
    } else if (dir == 'E') {
      d = E;
    } else if (dir == 'S') {
      d = S;
    } else if (dir == 'W') {
      d = W;
    }
  }
  bool move(char m, int upper, int right) {
    if (m == 'R') {
      if (d == W) {
        d = N;
      } else {
        int t = d + 1;
        d = (enum direction)t;
      }
    } else if (m == 'L') {
      if (d == N) {
        d = W;
      } else {
        int t = d - 1;
        d = (enum direction)t;
      }
    } else if (m == 'F') {
      if (d == N) {
        if (posy + 1 > upper) {
          if (scene.find({posx, posy}) != scene.end()) {
          } else {
            scene.insert({posx, posy});
            // cout << "add scene" << posx << " " << posy << endl;
            return true;
          }
        } else {
          posy += 1;
        }
      } else if (d == E) {
        if (posx + 1 > right) {
          if (scene.find({posx, posy}) != scene.end()) {
          } else {
            scene.insert({posx, posy});
            // cout << "add scene" << posx << " " << posy << endl;
            return true;
          }
        } else {
          posx += 1;
        }
      } else if (d == S) {
        if (posy - 1 < 0) {
          if (scene.find({posx, posy}) != scene.end()) {
          } else {
            scene.insert({posx, posy});
            // cout << "add scene" << posx << " " << posy << endl;
            return true;
          }
        } else {
          posy -= 1;
        }
      } else if (d == W) {
        if (posx - 1 < 0) {
          if (scene.find({posx, posy}) != scene.end()) {
          } else {
            scene.insert({posx, posy});
            // cout << "add scene" << posx << " " << posy << endl;
            return true;
          }
        } else {
          posx -= 1;
        }
      }
    }

    // cout << posx << " " << posy << endl;
    return false;
  }
};

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  cin.tie(0);

  int upper, right;
  cin >> right >> upper;

  int posx, posy;
  char direction;

  while (cin >> posx >> posy >> direction) {
    robot *r = new robot(posx, posy, direction);
    string dirs;
    cin >> dirs;
    bool lost = false;
    for (auto d : dirs) {
      if (r->move(d, upper, right)) {
        lost = true;
        break;
      }
    }

    if (r->d == N) {
      cout << r->posx << " " << r->posy << " N";
    } else if (r->d == E) {
      cout << r->posx << " " << r->posy << " E";
    } else if (r->d == S) {
      cout << r->posx << " " << r->posy << " S";
    } else if (r->d == W) {
      cout << r->posx << " " << r->posy << " W";
    }

    if (lost) {
      cout << " LOST" << endl;
    } else {
      cout << endl;
    }
  }

  return 0;
}
