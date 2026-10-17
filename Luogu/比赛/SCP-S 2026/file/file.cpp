#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MAXN = 1e6 + 10;

int n, m, a[MAXN];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; cin >> a[i++]);
  sort(a + 1, a + n + 1, greater<int>());
  vector<i64> res;
  for (int i = 1, l; i <= m; i++) {
    cin >> l;
    vector<int> vec(l);
    for (int j = 0; j < l; cin >> vec[j++]);
    sort(vec.begin(), vec.end(), greater<int>());
    i64 sum = 0;
    for (int x = 0, y = 1; x < l; x++) {
      for (; y <= n && a[y] > vec[x]; y++);
      sum += y - 1;
    }
    res.push_back(sum);
  }
  sort(res.begin(), res.end());
  i64 sum = 1ll * n * (n + 1) >> 1, ans = 0;
  for (i64 x : res) sum += x, ans += sum;
  cout << ans;
  return 0;
}