#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 10;

int n;

struct s {
  char s[10];
  int a, b, c, id, sum;
} a[MAXN];

bool cmp(const s &i, const s &j) {
  if (i.sum != j.sum) {
    return i.sum > j.sum;
  } else {
    return i.id < j.id;
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].s >> a[i].a >> a[i].b >> a[i].c;
    a[i].id = i, a[i].sum = a[i].a + a[i].b + a[i].c;
  }
  sort(a + 1, a + n + 1, cmp);
  cout << a[1].s << ' ' << a[1].a << ' ' << a[1].b << ' ' << a[1].c;
  return 0;
}