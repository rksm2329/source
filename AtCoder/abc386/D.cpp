#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;

struct Node {
  int x, y;
  char c;
} a[MAXN];

int n, m;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i].x >> a[i].y >> a[i].c;
  }
  sort(a + 1, a + m + 1, [](const Node &i, const Node &j) {
    return i.x < j.x || (i.x == j.x && i.y < j.y);
  });
  int mi = 2e9;
  for (int i = 1; i <= m; i++) {
    if (a[i].c == 'W') {
      mi = min(mi, a[i].y);
    } else {
      if (a[i].y >= mi) {
        cout << "No";
        return 0;
      }
    }
  }
  cout << "Yes";
  return 0;
}