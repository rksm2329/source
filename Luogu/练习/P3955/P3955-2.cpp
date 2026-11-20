#include <climits>
#include <iostream>

using namespace std;

const int MAXN = 1e3 + 10;

struct node {
  int x, len;
} a[MAXN];

int n, q, l, x;

int main() {
  cin >> n >> q;
  for (int i = 1, x; i <= n; i++) {
    cin >> x;
    int cnt = 0;
    for (int t = x; t; t /= 10) {
      cnt++;
    }
    a[i] = {x, cnt};
  }
  for (int i = 1; i <= q; i++) {
    cin >> l >> x;
    int mi = INT_MAX;
    for (int j = 1; j <= n; j++) {
      if (a[j].len < l) {
        continue;
      }
      bool f = 0;
      for (int t1 = x, t2 = a[j].x; t1 && t2; t1 /= 10, t2 /= 10) {
        if (t1 % 10 != t2 % 10) {
          f = 1;
          break;
        }
      }
      if (!f) {
        mi = min(mi, a[j].x);
      }
    }
    if (mi == INT_MAX) {
      cout << -1 << '\n';
    } else {
      cout << mi << '\n';
    }
  }
  return 0;
}