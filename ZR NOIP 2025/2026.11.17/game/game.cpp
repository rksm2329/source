#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 4e5 + 10;

int n, a[MAXN];

int main() {
  freopen("game.in", "r", stdin);
  freopen("game.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  bool flag = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i == 1) continue;
    if (a[i] != a[i - 1] + 1) flag = 0;
  }
  if (!flag && n <= 50) flag = 1;
  cout << (flag ? "Yes" : "No");
  return 0;
}