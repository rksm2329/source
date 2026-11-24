#include <bits/stdc++.h>
#define localtest

using namespace std;
using ll = long long;

const int MAXN = 1e3 + 10;

int n, m, a[4][MAXN];
vector<int> g[MAXN];

int main() {
  #ifndef localtest
  freopen("path.in", "r", stdin);
  freopen("path.out", "w", stdout);
  #endif
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; cin >> a[j++][i]);
  }
  
  return 0;
}