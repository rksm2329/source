#include <iomanip>
#include <iostream>

using namespace std;

int k, num, b, fh = 1, pos = 1;
bool f;
char a, c;

int main() {
  while (cin >> c) {
    if (c == '-') {
      b += pos * fh * num;
      num = 0, fh = -1, f = 0;
    }
    if (c == '+') {
      b += pos * fh * num;
      num = 0, fh = 1, f = 0;
    }
    if (c == '=') {
      b += pos * fh * num;
      num = 0, fh = 1, pos = -1, f = 0;
    }
    if (c >= 'a' && c <= 'z') {
      if (f) {
        k += pos * fh * num;
        num = 0;
      } else {
        k += pos * fh;
      }
      a = c, f = 0;
    }
    if (c >= '0' && c <= '9') {
      num = num * 10 + (c - '0');
      f = 1;
    }
  }
  b += pos * fh * num;
  double t = double(-b * 1.0 / k);
  if (t == -0.0) {
    t = 0;
  }
  cout << a << '=' << fixed << setprecision(3) << t;
  return 0;
}