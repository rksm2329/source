#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int MAXN = 1e6 + 10, B = 91;

string s;
ull pre[MAXN], h[MAXN];

ull get(int l, int r) {
  return l > r ? 0 : h[r] - h[l - 1] * pre[r - l + 1];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> s;
  pre[0] = 1;
  int n = s.size();
  s = '#' + s;
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] * B;
    h[i] = h[i - 1] * B + s[i];
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    int j = n - i + 1;
    int l = 1, r = i, now = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (get(1, mid) == get(j, j + mid - 1)) {
        now = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    if (now == i) {
      ans = i;
      continue;
    }
    int pos = now + 1;
    bool flag = 0;
    ull hs = get(1, i) - s[pos] * pre[i - pos];
    for (char c = 'a'; c <= 'z'; c++) {
      ull x = hs + c * pre[i - pos];
      ull y = get(j, n);
      if (j <= pos) y += c * pre[n - pos] - s[pos] * pre[n - pos];
      if (x == y) {
        flag = 1, ans = i;
        break;
      }
    }
    if (flag) continue;
    int pos2 = n - i + pos;
    hs = get(j, n) - s[pos2] * pre[n - pos2];
    for (char c = 'a'; c <= 'z'; c++) {
      ull x = hs + c * pre[n - pos2];
      ull y = get(1, i);
      if (i >= pos2) y += c * pre[i - pos2] - s[pos2] * pre[i - pos2];
      if (x == y) {
        flag = 1, ans = i;
        break;
      }
    }
  }
  cout << ans;
  return 0;
}