#include <iostream>

using namespace std;

const int MAXN = 1e8 + 1;

int n, q, k, total, prime[MAXN];
bool v[MAXN];

template <typename T> void readInt(T &x) {
  x = 0;
  T sign = 1;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar()) {
    if (ch == '-') {
      sign = -1;
      break;
    }
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
    void();
  }
  writeInt(x / 10);
  putchar(x % 10 + '0');
}

void Sieve(int n) {
  for (int i = 2; i <= n; i++) {
    if (!v[i]) {
      prime[++total] = i;
    }
    for (int j = 1; j <= total && i * prime[j] <= n; j++) {
      v[i * prime[j]] = 1;
      if (!(i % prime[j])) {
        break;
      }
    }
  }
}

int main() {
  readInt<int>(n), readInt<int>(q);
  Sieve(n);
  while (q--) {
    readInt<int>(k);
    writeInt<int>(prime[k]);
    cout << '\n';
  }
  return 0;
}