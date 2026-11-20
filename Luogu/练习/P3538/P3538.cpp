#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 5e5 + 10, B = 91, M = 998244353;

int n, m;
string s;
bool vis[MAXN];
vector<int> pr;
ll mif[MAXN], pre[MAXN], h[MAXN];

void Sieve() {
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) {
      pr.push_back(i), mif[i] = i;
    }
    for (int p : pr) {
      if (i * p > n) break;
      vis[i * p] = 1, mif[i * p] = p;
      if (i % p == 0) break;
    }
  }
}

ll gethash(int l, int r) {
  return (h[r] - h[l - 1] * pre[r - l + 1] % M + M) % M;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> s;
  Sieve();
  s = '#' + s, pre[0] = 1;
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] * B % M;
    h[i] = (h[i - 1] * B + s[i]) % M;
  }
  cin >> m;
  for (int l, r; m--; ) {
    cin >> l >> r;
    int len = r - l + 1, ans = len;
    for (; len > 1; len /= mif[len]) {
      if (gethash(l + ans / mif[len], r) == gethash(l, r - ans / mif[len])) ans /= mif[len];
    }
    cout << ans << '\n';
  }
  return 0;
}