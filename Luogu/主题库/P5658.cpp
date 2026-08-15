#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 5e5 + 10;

int n, stk[MAXN], fa[MAXN];
ll f[MAXN], ans;
string s;
vector<int> g[MAXN];

void dfs(int u, ll pre, int top) {
  int last = 0;
  if (s[u] == '(') stk[++top] = u;
  else {
    if (!top) f[u] = 0;
    else {
      last = stk[top], f[u] = f[fa[stk[top]]] + 1;
      pre += f[u], top--;
    }
  }
  ans ^= u * pre;
  for (int v : g[u]) dfs(v, pre, top);
  if (last) stk[top + 1] = last;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> s;
  s = '#' + s;
  for (int u = 2; u <= n; u++) {
    cin >> fa[u];
    g[fa[u]].push_back(u);
  }
  dfs(1, 0, 0);
  cout << ans;
  return 0;
}