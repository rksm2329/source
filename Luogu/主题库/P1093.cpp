#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 3e2 + 10;

int n;

struct s {
  int ch, mth, eng, sum, id;
} a[MAXN];

bool cmp(const s &i, const s &j) {
  if (i.sum != j.sum) {
    return i.sum > j.sum;
  } else {
    if (i.ch != j.ch) {
      return i.ch > j.ch;
    } else {
      return i.id < j.id;
    }
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].ch >> a[i].mth >> a[i].eng;
    a[i].sum = a[i].ch + a[i].mth + a[i].eng, a[i].id = i;
  }
  stable_sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= 5; i++) {
    cout << a[i].id << ' ' << a[i].sum << '\n';
  }
  return 0;
}