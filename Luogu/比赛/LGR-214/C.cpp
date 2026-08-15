#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, l, r;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> l >> r;
  for (int i = 1; i < n; i++) {
    cout << r / n << ' ';
  }
  
  return 0;
}