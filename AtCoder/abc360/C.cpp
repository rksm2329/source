#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

struct Node {
  int x, w;
} a[MAXN];

int n;
vector<int> v[MAXN];

bool cmp(const Node &i, const Node &j) {
  return i.w < j.w;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i].w;
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    v[a[i].x].push_back(a[i].w);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (v[i].size() > 1) {
      for (int j = 0; j < v[i].size() - 1; j++) {
        ans += v[i][j];
      }
    }
  }
  cout << ans;
  return 0;
}