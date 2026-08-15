#include <bits/extc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const int MAXN = 1e6 + 10;

int n, minf[MAXN];
ull h[MAXN], fac[MAXN];
vector<int> pr;
bool vis[MAXN];

void init(int n) {
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) {
      pr.push_back(i);
      minf[i] = i;
    }
    for (int p : pr) {
      if (1ll * i * p > n) break;
      minf[i * p] = p, vis[i * p] = 1;
      if (i % p == 0) break;
    }
  }
  for (int i = 2; i <= n; i++) {
    for (int k = i; k > 1; ) {
      int x = minf[k];
      for (; k % x == 0; k /= x, fac[i] ^= h[x]);
    }
    fac[i] ^= fac[i - 1];
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  mt19937_64 rnd(time(nullptr));
  cin >> n;
  if (n == 1) {
    cout << 1 << '\n' << 1;
    return 0;
  }
  for (int i = 1; i <= n; h[i++] = rnd());
  init(n);
  ull sum = 0;
  for (int i = 1; i <= n; sum ^= fac[i++]);
  if (!sum) {
    cout << n << '\n';
    for (int i = 1; i <= n; i++) cout << i << ' ';
  }
  for (int i = 1; i <= n; i++) {
    if (fac[i] == sum) {
      cout << n - 1 << '\n';
      for (int j = 1; j <= n; j++) {
        if (j == i) continue;
        cout << j << ' ';
      }
      return 0;
    }
  }
  __gnu_pbds::gp_hash_table<ull, int> mp;
  int x = 0, y = 0;
  for (int i = 1; i <= n; i++) {
    if (mp.find(sum ^ fac[i]) != mp.end()) {
      x = mp[sum ^ fac[i]], y = i;
      break;
    }
    mp[fac[i]] = i;
  }
  if (x && y) {
    cout << n - 2 << '\n';
    for (int i = 1; i <= n; i++) {
      if (i == x || i == y) continue;
      cout << i << ' ';
    }
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (fac[i] == (sum ^ fac[2] ^ fac[n])) {
      cout << n - 3 << '\n';
      for (int j = 1; j <= n; j++) {
        if (j == 2 || j == i || j == n) continue;
        cout << j << ' ';
      }
      return 0;
    }
  }
  return 0;
}