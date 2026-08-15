#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

int n, a[MAXN], id[MAXN];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    id[a[i]] = i;
  }
  int vd = id[0];
  for (int i = 1; i < n; i++) {
    swap(a[id[i]], a[vd]);
    swap(vd, id[i]);
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
  return 0;
}