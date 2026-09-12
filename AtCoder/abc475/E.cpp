#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 30080;

int n, m, k, q;
string s[MAXN], t;
bitset<MAXN> c[205], mask, und, pas, tmp;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> k >> t;
  for (int i = 1; i <= n; i++) cin >> s[i];
  for (int i = 1; i <= n; i++) mask.set(i);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      if (s[i][j - 1] == t[j - 1]) {
        c[j].set(i);
      }
    }
  }
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    c[v].flip(u);
    int tot = 0;
    und = mask;
    pas.reset();
    for (int j = 1; j <= k; j++) {
      if (!und[u] || tot == m) break;
      tmp = und & c[j];
      int cnt = tmp.count();
      if (tot + cnt <= m) {
        tot += cnt;
        pas |= tmp;
        und ^= tmp;
      } else {
        und = tmp;
      }
    }
    if (pas[u]) cout << "Yes\n";
    else cout << "No\n";
  }
  return 0;
}