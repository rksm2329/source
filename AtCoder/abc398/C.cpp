#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 3e5 + 10;

int n, a[MAXN];
map<int, int> mp;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  int mx = 0, pos = -1;
  for (int i = n; i >= 1; i--) {
    if (mp[a[i]] == 1 && a[i] > mx) {
      mx = a[i], pos = i;
    }
  }
  cout << pos;
  return 0;
}