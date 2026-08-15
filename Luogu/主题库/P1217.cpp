#include <iostream>

using namespace std;

const int MAXN = 1e8 + 1;

int a, b, tot, v[MAXN], prime[MAXN];
string ans;

bool check(int x) {
  ans = "";
  while (x) {
    ans += x % 10 + '0';
    x /= 10;
  }
  int l = ans.size();
  for (int i = 0, j = l - 1; i <= j; i++, j--) {
    if (ans[i] != ans[j]) {
      return 0;
    }
  }
  return 1;
}

void Sieve(int n) {
  for (int i = 2; i <= n; i++) {
    if (!v[i]) {
      prime[++tot] = i;
    }
    for (int j = 1; j <= tot && i * prime[j] <= n; j++) {
      v[i * prime[j]] = 1;
      if (i % prime[j] == 0) {
        break;
      }
    }
  }
}

int main() {
  cin >> a >> b;
  Sieve(b);
  for (int i = 1; i <= tot; i++) {
    if (prime[i] < a || prime[i] > b) {
      continue;
    }
    if (check(prime[i])) {
      cout << prime[i] << '\n';
    }
  }
  return 0;
}