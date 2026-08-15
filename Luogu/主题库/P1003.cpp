#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 10;

struct node {
  int a, b, g, k, id;
} t[MAXN];

int n, x, y;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t[i].a >> t[i].b >> t[i].g >> t[i].k;
    t[i].id = i;
  }
  cin >> x >> y;
  for (int i = n; i >= 1; i--) {
    if (x >= t[i].a && y >= t[i].b && x <= t[i].g + t[i].a &&
        y <= t[i].k + t[i].b) {
      cout << t[i].id;
      return 0;
    }
  }
  cout << -1;
  return 0;
}