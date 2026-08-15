#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;

int n;
pair<int, int> a[MAXN];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a + 1, a + n + 1, greater<pair<int, int>>());
  cout << a[2].second;
  return 0;
}