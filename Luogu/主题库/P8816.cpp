#include <algorithm>
#include <iostream>

using namespace std;

bool book[1005][1005];
int a[1005], b[1005];
int n, k;
int ans = 0;

void dfs(int x, int y, int dis, int num) {
  if (book[x][y] == 0) {
    num--;
  }
  if (num < 0) {
    ans = max(ans, dis - 1);
    return;
  }
  dfs(x + 1, y, dis + 1, num);
  dfs(x, y + 1, dis + 1, num);
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    book[a[i]][b[i]] = 1;
  }
  for (int i = 1; i <= n; i++) {
    dfs(a[i], b[i], 1, k);
  }
  cout << ans;
  return 0;
}