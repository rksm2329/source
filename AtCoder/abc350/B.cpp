#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 10;

int n, q, a[MAXN];
bool vis[MAXN];

int main() {
  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    cin >> a[i];
    if (!vis[a[i]]) {
      n--;
      vis[a[i]] = 1;
    } else {
      n++;
      vis[a[i]] = 0;
    }
  }
  cout << n;
  return 0;
}