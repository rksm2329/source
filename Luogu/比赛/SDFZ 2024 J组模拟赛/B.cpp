#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

struct Node {
  int pre, nxt;
} a[MAXN];

int n, m, h = 1, t = n;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  a[1].nxt = 2, a[n].pre = n - 1;
  for (int i = 2; i < n; i++) {
    a[i].pre = i - 1;
    a[i].nxt = i + 1;
  }
  for (int i = 1, x, y; i <= m; i++) {
    cin >> x >> y;
    if (x == h) {
      a[a[x].nxt].pre = 0;
      h = a[x].nxt;
    } else if (x == t) {
      a[a[x].pre].nxt = 0;
      t = a[x].pre;
    } else {
      a[a[x].nxt].pre = a[x].pre;
      a[a[x].pre].nxt = a[x].nxt;
    }
    a[x].pre = y;
    a[x].nxt = a[y].nxt;
    a[a[y].nxt].pre = x;
    a[y].nxt = x;
    if (y == t) {
      t = x;
    }
  }
  for (int i = h; i; i = a[i].nxt) {
    cout << i << ' ';
  }
  return 0;
}