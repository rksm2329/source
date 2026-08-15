#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
char buf[1 << 21], *p1, *p2;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)

int n, m, l, r, k, x, a[MAXN];

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
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  readInt<int>(n), readInt<int>(m);
  for (int i = 1; i <= n; i++) {
    readInt<int>(a[i]);
  }
  while (m--) {
    int op;
    readInt<int>(op);
    switch (op) {
    case 1: {
      readInt<int>(l), readInt<int>(r);
      long long sum = 0;
      for (int i = l; i <= r; i++) {
        sum += a[i];
      }
      writeInt<long long>(sum), putchar('\n');
      break;
    }
    case 2: {
      readInt<int>(l), readInt<int>(r), readInt<int>(x);
      __int128 h = ((__int128)1 << 64) / x;
      for (int i = l; i <= r; i++) {
        if (a[i] >= x) {
          a[i] -= ((__int128)a[i] * h >> 64) * x;
          if (a[i] >= x) {
            a[i] -= x;
          }
        }
      }
      break;
    }
    case 3: {
      readInt<int>(k), readInt<int>(x);
      a[k] = x;
      break;
    }
    }
  }
  return 0;
}