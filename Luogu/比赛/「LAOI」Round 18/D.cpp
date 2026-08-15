#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 1e5 + 10, INF = 1e9;

int n, deg[MAXN], fa[MAXN], cnt[MAXN];
pii info[MAXN], global;
multiset<int> st[MAXN];

/*
? info[u]: u 的儿子的最大值 - 1
? global: 全局最大值 - 1
? ans: 现在的答案
? ans = 最大的两个相加 - 1（之间没有直接连边），或相加 - 2（有直接连边）
? 
*/

void update(int u, int v) {
  cnt[deg[v]]--;
  if (st[fa[v]].find(deg[v]) != st[fa[v]].end()) st[fa[v]].erase(st[fa[v]].find(deg[v]));
  deg[u]++, deg[v]++, fa[u] = v;
  st[v].insert(deg[u]), st[fa[v]].insert(deg[v]);
  cnt[deg[u]]++, cnt[deg[v]]++;
  if (deg[v] - 1 > global.first) global = {deg[v] - 1, 1};
  else if (deg[v] - 1 == global.first) global.second++;
  if (deg[u] - 1 > global.first) global = {deg[u] - 1, 1};
  else if (deg[u] - 1 == global.first) global.second++;
  if (deg[v] - 1 > info[fa[v]].first) info[fa[v]] = {deg[v] - 1, 1};
  else if (deg[v] - 1 == info[fa[v]].first) info[fa[v]].second++;
  if (deg[u] - 1 > info[v].first) info[v] = {deg[u] - 1, 1};
  else if (deg[u] - 1 == info[v].first) info[v].second++;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  int ans = 0, mx = 0;
  global = {-1, 1};
  for (int u = 2, v; u <= n; u++) {
    cin >> v;
    if (u == 2) {
      update(u, v);
      cout << "0\n";
      continue;
    }
    if (ans == deg[v] + info[v].first - 1) {
      cout << ++ans << '\n';
      update(u, v);
      continue;
    }
    int val = ans - deg[v] + 1;
    int now1 = cnt[val], now2 = st[v].count(val + 1);
    if (val == deg[v]) now1--;
    if (deg[fa[v]] == val + 1) now2++;
    if (now1 + now2) ans++;
    ans = max(ans, deg[v] - 1);
    update(u, v);
    cout << ans << '\n';
  }
  return 0;
}