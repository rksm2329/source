#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10;

int n, k, a[MAXN], b[MAXN], tot;

void dfs(int x, int sum) {
  if (x == n + 1) {
    if (sum % k == 0) {
      for (int i = 1; i <= n; i++) {
        cout << b[i] << ' ';
      }
      cout << '\n';
    }
  }
  for (int i = 1; i <= a[x]; i++) {
    b[++tot] = i;
    dfs(x + 1, sum + i);
    tot--;
  }
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dfs(1, 0);
  return 0;
}