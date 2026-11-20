#include <algorithm>
#include <iostream>


using namespace std;

const int MAXN = 2e5 + 10;

struct node {
  int pre, id;
} a[MAXN];

int n, q, op, x, v, p[MAXN];

bool cmp(const node &i, const node &j) {
  if (i.pre != j.pre) {
    return i.pre < j.pre;
  }
  return i.id < j.id;
}

void l_sort() {
  for (int i = n; i >= 2; i--) {
    if (cmp(a[i], a[i - 1])) {
      swap(a[i], a[i - 1]);
    }
  }
}
void r_sort() {
  for (int i = 2; i <= n; i++) {
    if (cmp(a[i], a[i - 1])) {
      swap(a[i], a[i - 1]);
    }
  }
}

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].pre;
    a[i].id = i;
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    p[a[i].id] = i;
  }
  while (q--) {
    cin >> op;
    if (op == 1) {
      cin >> x >> v;
      a[p[x]].pre = v;
      l_sort();
      r_sort();
      for (int i = 1; i <= n; i++) {
        p[a[i].id] = i;
      }
    } else {
      cin >> x;
      cout << p[x] << '\n';
    }
  }
  return 0;
}