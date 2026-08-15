#include <iostream>

using namespace std;

int n;

bool check(int n) {
  if (n == 1)
    return 0;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

void dfs(int x, int ans) {
  if (x == n + 1) {
    cout << ans << '\n';
    return;
  }
  for (int i = 1; i <= 9; i++) {
    if (check(ans * 10 + i)) {
      dfs(x + 1, ans * 10 + i);
    }
  }
}

int main() {
  cin >> n;
  dfs(1, 0);
  return 0;
}