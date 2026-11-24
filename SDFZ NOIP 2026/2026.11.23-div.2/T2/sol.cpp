#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  vector<pii> vec;
  for (int i = 1, l, r; i <= m << 1; i++) {
    cin >> l >> r;
    if (l < r) vec.push_back({l, r});
  }
  sort(vec.begin(), vec.end(), [] (const pii &i, const pii &j) {
    return i.first < j.first || (i.first == j.first && i.second > j.second);
  });
  if (vec.size() < m) {
    cout << -1;
    return 0;
  }
  auto &[p, q] = vec[m - 1];
  for (int i = 1; i <= p; i++) cout << 1000000000 << ' ';
  for (int i = p + 1; i < q; i++) cout << i << ' ';
  cout << 1000000000 << ' ';
  for (int i = q + 1; i <= n; i++) cout << i << ' ';
  return 0;
}