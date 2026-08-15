#include <iostream>

using namespace std;

int n, ans, a[30], b[30], p[30];

void dfs(int x) {
  if (x > n) {
    ans++;
    return;
  }
  if (p[a[x]] == 0) {
    p[a[x]] = 1;
    dfs(x + 1);
    p[a[x]] = 0;
  }
  if (p[b[x]] == 0) {
    p[b[x]] = 1;
    dfs(x + 1);
    p[b[x]] = 0;
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  dfs(1);
  cout << ans;
  return 0;
}