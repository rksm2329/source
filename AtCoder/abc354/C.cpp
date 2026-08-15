#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

struct Node {
  int a, c, id;
} a[MAXN];

int n, m, out[MAXN];
bool vis[MAXN];

bool cmp(const Node &i, const Node &j) {
  if (i.a > j.a) {
    if (i.c < j.c) {
      out[++m] = j.id;
      vis[j.id] = 1;
    }
    return 1;
  } else if (i.a < j.a) {
    if (i.c > j.c) {
      out[++m] = i.id;
      vis[i.id] = 1;
    }
    return 0;
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].a >> a[i].c;
    a[i].id = i;
  }
  sort(a + 1, a + n + 1, cmp);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      ans++;
    }
  }
  cout << ans << '\n';
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      cout << i << ' ';
    }
  }
  return 0;
}