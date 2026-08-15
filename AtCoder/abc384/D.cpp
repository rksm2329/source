#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 4e5 + 10;

int n, a[MAXN];
ll k, sum[MAXN];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i + n] = a[i];
  }
  for (int i = 1; i <= 2 * n; i++) {
    sum[i] = sum[i - 1] + a[i];
  }
  k %= sum[n];
  map<ll, bool> mp;
  mp[0] = 1;
  for (int i = 0; i <= n * 2; i++) {
    if (mp[sum[i] - k]) {
      cout << "Yes";
      return 0;
    }
    mp[sum[i]] = 1;
  }
  cout << "No";
  return 0;
}