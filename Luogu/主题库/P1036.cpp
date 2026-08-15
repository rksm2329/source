#include <iostream>

using namespace std;

int n, k, ans, a[30], b[30];

bool check(int x) {
  if (x == 1)
    return 0;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}

void dfs(int x, int last) {
  if (x == k + 1) {
    int sum = 0;
    for (int i = 1; i <= k; i++) {
      sum += a[i];
    }
    ans += check(sum);
    return;
  }
  for (int i = last + 1; i <= n; i++) {
    a[x] = b[i];
    dfs(x + 1, i);
  }
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  dfs(1, 0);
  cout << ans;
  return 0;
}