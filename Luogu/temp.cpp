#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 4e2 + 10;

int n, a[MAXN][MAXN], cnt[2][MAXN * MAXN];
vector<int> lsh;

int rnk(int x) {
  return lower_bound(lsh.begin(), lsh.end(), x) - lsh.begin() + 1;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      lsh.push_back(a[i][j]);
    }
  }
  sort(lsh.begin(), lsh.end());
  lsh.erase(unique(lsh.begin(), lsh.end()), lsh.end());
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) a[i][j] = rnk(a[i][j]);
  }
  int w = lsh.size();
  for (int r = 1; r <= n; r++) {
    fill(&cnt[0][0], &cnt[1][w] + 1, 0);
    pii mx[2];
    for (int c = 1; c <= n; c++) {
      for (int i = 1; i <= r; i++) {
        bool k = i + c & 1;
        cnt[k][a[i][c]]++;
        if (cnt[k][a[i][c]] >= cnt[k][mx[k].first]) {
          if (a[i][c] != mx[k].first) mx[k].second = mx[k].first, mx[k].first = a[i][c];
        } else if (cnt[k][a[i][c]] > cnt[k][mx[k].second] && a[i][c] != mx[k].second) mx[k].second = a[i][c];
      }
      if (mx[0].first != mx[1].first) {
        cout << r * c - cnt[0][mx[0].first] - cnt[1][mx[1].first] << ' ';
      } else {
        cout << r * c - max(cnt[0][mx[0].second] + cnt[1][mx[1].first], cnt[0][mx[0].first] + cnt[1][mx[1].second]) << ' ';
      }
    }
    cout << '\n';
  }
  return 0;
}