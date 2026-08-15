#include <iostream>

using namespace std;

const int MAXN = 1e3 + 10;

struct node {
  int x, y;
} cnt[MAXN];

int n, m, a[MAXN], ans;
bool op;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> op;
      cnt[j].x += op;
      cnt[j].y += !op;
    }
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    if ((cnt[i].x > cnt[i].y && a[i] == 1) ||
        (cnt[i].x < cnt[i].y && a[i] == 0)) {
      ans++;
    }
  }
  cout << ans;
  return 0;
}