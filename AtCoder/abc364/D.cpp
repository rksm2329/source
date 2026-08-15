#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n, q, a[MAXN];

bool C(int b, int k, int x) {
  int i1 = upper_bound(a + 1, a + n + 1, b + x) - a;
  int i2 = lower_bound(a + 1, a + n + 1, b - x) - a;
  return i1 - i2 >= k;
}

int F(int b, int k) {
  int l = -2e8, r = 2e8;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (C(b, k, mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return l;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1, b, k; i <= q; i++) {
    cin >> b >> k;
    cout << F(b, k) << '\n';
  }
  return 0;
}