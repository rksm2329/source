#include <iostream>
#include <cctype>

using namespace std;

string x, y;
string in, out;

void Solve1() {
  int cnt = x[0] - '0';
  for (; cin >> in >> out; cnt++) {
    bool f = 0;
    for (int i = 0; i < in.size(); i++) {
      if (isdigit(in[i])) {
        if (!f) {
          cout << cnt;
          f = 1;
        }
      } else {
        cout << in[i];
      }
    }
    cout << ' ';
    f = 0;
    for (int i = 0; i < out.size(); i++) {
      if (isdigit(out[i])) {
        if (!f) {
          cout << cnt;
          f = 1;
        }
      } else {
        cout << out[i];
      }
    }
    cout << '\n';
  }
}

void Solve2() {
  cin >> y;
  int cnt = 0;
  for (int i = 0; i < x.size(); i++) {
    if (isdigit(x[i])) {
      cnt = cnt * 10 + x[i] - '0';
    }
  }
  for (; cin >> in >> out; cnt++) {
    bool f = 0;
    for (int i = 0; i < x.size(); i++) {
      if (isdigit(x[i])) {
        if (!f) {
          cout << cnt;
          f = 1;
        }
      } else {
        cout << x[i];
      }
    }
    cout << ' ';
    f = 0;
    for (int i = 0; i < x.size(); i++) {
      if (isdigit(x[i])) {
        if (!f) {
          cout << cnt;
          f = 1;
        }
      } else {
        cout << x[i];
        if (x[i] == '.') {
          cout << y;
          break;
        }
      }
    }
    if (!f) {
      cout << cnt;
    }
    cout << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> x;
  if (x[0] == '0' || x[0] == '1') {
    Solve1();
  } else {
    Solve2();
  }
  return 0;
}