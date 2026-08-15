#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

int n;
long long a[MAXN];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ans ^= a[i];
  }
  cout << ans << ' ' << 0;
  return 0;
}