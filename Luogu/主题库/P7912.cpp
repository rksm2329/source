#include <iostream>

using namespace std;

const int MAXN = 2e5 + 10;

struct node {
  int pre, nxt;
  int x;
} a[MAXN];

int n, x, h = 1, t, total, cnt[MAXN];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    t = i;
    a[i].x = x;
    if (i == 1) {
      a[i].nxt = i + 1;
      continue;
    }
    if (i == n) {
      a[i].pre = i - 1;
      continue;
    }
    a[i].nxt = i + 1, a[i].pre = i - 1;
  }
  while (h) {
    total = 0;
    for (int i = h; i; i = a[i].nxt) {
      if (!a[i].pre) {
        cout << i << ' ';
        cnt[++total] = i;
        continue;
      }
      if (a[i].x != a[a[i].pre].x) {
        cout << i << ' ';
        cnt[++total] = i;
      }
    }
    for (int i = 1; i <= total; i++) {
      if (h == t) {
        h = t = 0;
        break;
      }
      if (!a[cnt[i]].nxt) {
        a[a[cnt[i]].pre].nxt = a[cnt[i]].nxt;
        t = a[cnt[i]].pre;
        a[cnt[i]].pre = a[cnt[i]].nxt = 0;
        continue;
      }
      if (!a[cnt[i]].pre) {
        a[a[cnt[i]].nxt].pre = a[cnt[i]].pre;
        h = a[cnt[i]].nxt;
        a[cnt[i]].pre = a[cnt[i]].nxt = 0;
        continue;
      }
      a[a[cnt[i]].nxt].pre = a[cnt[i]].pre;
      a[a[cnt[i]].pre].nxt = a[cnt[i]].nxt;
      a[cnt[i]].pre = a[cnt[i]].nxt = 0;
    }
    cout << '\n';
  }
  return 0;
}