#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 5e5 + 10;

int n, q, ans, a[MAXN];

void Work() {
  int x;
  cin >> x;
  if (x == 1) {
    ans += !a[x + 1] * (!a[x] ? 1 : -1);
  } else if (x == n) {
    ans += !a[x - 1] * (!a[x] ? 1 : -1);
  } else {
    if ((!a[x] && !a[x - 1] && !a[x + 1]) || (a[x] && a[x - 1] && a[x + 1])) {
      ans++;
    } else if ((!a[x] && a[x - 1] && a[x + 1]) || (a[x] && !a[x - 1] && !a[x + 1])) {
      ans--;
    }
  }
  cout << ans << '\n';
  a[x] ^= 1;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  for (cin >> n >> q; q--; Work());
  return 0;
}