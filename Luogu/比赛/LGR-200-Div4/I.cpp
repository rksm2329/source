#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e3 + 10;

int n, b[MAXN];
pair<int, int> a[MAXN];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i].second;
  }
  pair<int, int> cnt = {0, 0};
  for (int i = 1; i <= n; i++) {
    if (a[i].first > a[i].second) {
      cnt.first++;
    } else if (a[i].first < a[i].second) {
      cnt.second++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i].second < a[i].first) {
      b[i] = 0;
    } else {
      b[i] = a[i].second - a[i].first + 1;
    }
  }
  sort(b + 1, b + n + 1);
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (b[i]) {
      if (cnt.first == cnt.second && b[i] > 1) {
        ans += b[i] - 1;
        cnt.first++;
      } else {
        ans += b[i];
        cnt.first++;
        if (b[i] > 1) {
          cnt.second--;
        }
      }
    }
    if (cnt.first > cnt.second) {
      break;
    }
  }
  cout << ans;
  return 0;
}