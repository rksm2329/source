#include <bits/stdc++.h>

using namespace std;

int n, m, a[110];
bool vis[110];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    char c;
    cin >> a[i] >> c;
    if (c == 'M' && !vis[a[i]]) {
      cout << "Yes\n";
      vis[a[i]] = 1;
    } else {
      cout << "No\n";
    }
  }
  return 0;
}