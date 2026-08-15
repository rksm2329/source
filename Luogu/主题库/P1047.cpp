#include <iostream>

using namespace std;

const int MAXN = 1e4 + 10;

int l, m, u, v;
bool a[MAXN];

int main() {
  cin >> l >> m;
  for (int i = 0; i <= l; i++) {
    a[i] = 1;
  }
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    for (int i = u; i <= v; i++) {
      a[i] = 0;
    }
  }
  int ans = 0;
  for (int i = 0; i <= l; i++) {
    ans += a[i];
  }
  cout << ans;
  return 0;
}