#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

const int MAXN = 5e3 + 10;

int n, m;

struct s {
  int id, v;
} a[MAXN];

bool cmp(const s &i, const s &j) { return i.v > j.v; }

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].id >> a[i].v;
  }
  stable_sort(a + 1, a + n + 1, cmp);
  m = floor(m * 1.5);
  int fs = a[m].v;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i].v >= fs) {
      cnt++;
    } else {
      break;
    }
  }
  for (int i = 1; i <= cnt; i++) {
    for (int j = i + 1; j <= cnt; j++) {
      if (a[i].v == a[j].v) {
        if (a[i].id > a[j].id) {
          swap(a[i], a[j]);
        }
      }
    }
  }
  cout << fs << ' ' << cnt << '\n';
  for (int i = 1; i <= cnt; i++) {
    cout << a[i].id << ' ' << a[i].v << '\n';
  }
  return 0;
}