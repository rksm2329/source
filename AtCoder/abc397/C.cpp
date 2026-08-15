#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 3e5 + 10;

int n, a[MAXN], cnt[MAXN][2], res[2], ans;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]][1]++;
    res[1] += cnt[a[i]][1] == 1;
  }
  for (int i = 1; i <= n; i++) {
    ans = max(ans, res[0] + res[1]);
    cnt[a[i]][1]--, cnt[a[i]][0]++;
    res[0] += cnt[a[i]][0] == 1;
    res[1] -= cnt[a[i]][1] == 0;
  }
  cout << ans;
  return 0;
}