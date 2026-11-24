#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 1e6 + 10, INF = 1e9;

int n;
pii a[MAXN], b[MAXN];

bool check(int mid) {
  int cur1 = a[1].second, lst1 = a[1].first, cur2 = -1, lst2 = -1;
  bool ok1 = 1;
  for (int i = 2; i <= n; i++) {
    if (1ll * (a[i].first - lst1) * mid >= abs(cur1 - a[i].second)) cur1 = a[i].second, lst1 = a[i].first;
    else if (cur2 == -1 || (1ll * (a[i].first - lst2) * mid >= abs(cur2 - a[i].second))) cur2 = a[i].second, lst2 = a[i].first;
    else ok1 = 0;
  }
  bool ok2 = 1;
  for (int i = 2; i <= n / 2; i++) {
    if (1ll * (b[i].first - b[i - 1].first) * mid < abs(b[i].second - b[i - 1].second)) {
      ok2 = 0;
      break;
    }
  }
  for (int i = n / 2 + 2; i <= n; i++) {
    if (1ll * (b[i].first - b[i - 1].first) * mid < abs(b[i].second - b[i - 1].second)) {
      ok2 = 0;
      break;
    }
  }
  return ok1 | ok2;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    auto &[t, x] = a[i];
    cin >> t >> x, b[i] = {x, t};
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; i++) swap(b[i].first, b[i].second);
  sort(b + 1, b + n / 2 + 1);
  sort(b + n / 2 + 1, b + n + 1);
  int l = 0, r = INF;
  while (l < r) {
    int mid = l + r >> 1;
    check(mid) ? r = mid : l = mid + 1;
  }
  cout << l;
  return 0;
}