#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e2 + 10;

struct Node {
  int x, y;
} a[MAXN];

int n;
long long s1[MAXN], s2[MAXN], ans = LLONG_MAX;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  for (int i = 2; i < n; i++) {
    s1[i] = s1[i - 1] + abs(a[i].x - a[i - 1].x) + abs(a[i].y - a[i - 1].y);
  }
  for (int i = n - 1; i >= 2; i--) {
    s2[i] = s2[i + 1] + abs(a[i].x - a[i + 1].x) + abs(a[i].y - a[i + 1].y);
  }
  for (int i = 2; i < n; i++) {
    ans = min(ans, s1[i - 1] + s2[i + 1] + abs(a[i - 1].x - a[i + 1].x) + abs(a[i - 1].y - a[i + 1].y));
  }
  cout << ans;
  return 0;
}