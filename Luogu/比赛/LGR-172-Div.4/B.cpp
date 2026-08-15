#include <bits/stdc++.h>

using namespace std;

long long t, n, k;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  for (cin >> t; t--; ) {
    cin >> n >> k;
    cout << ((k + 1) * k / 2 <= n ? "Yes\n" : "No\n");
  }
  return 0;
}