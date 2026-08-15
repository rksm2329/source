#include <iostream>
#include "frac.h"

using namespace std;

int a, b;

template <typename T> void readInt(T &x) {
  x = 0;
  T sign = 1;
  char ch = getchar();
  bool f = 0;
  for (; ch < '0' || ch > '9'; ch = getchar()) {
    f = 1;
    if (ch == '-') {
      sign = -1;
      break;
    }
  }
  if (f) {
    ch = getchar();
  }
  for (; ch >= '0' && ch <= '9';
       x = (x << 3) + (x << 1) + ch - '0', ch = getchar()) {
  }
  x *= sign;
}

template <typename T> void writeInt(T x) {
  if (x < 0) {
    putchar('-'), x = -x;
  }
  if (x <= 9) {
    putchar(x + '0');
    return;
  }
  writeInt(x / 10);
  putchar(x % 10 + '0');
}

int main() {
  readInt<int>(a), readInt<int>(b);
  writeInt<int>(a + b);
  return 0;
}