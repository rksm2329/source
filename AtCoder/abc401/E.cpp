#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 3e5 + 10;

int n, m;
vector<int> g[MAXN];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  return 0;
}