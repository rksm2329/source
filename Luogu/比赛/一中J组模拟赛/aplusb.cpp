#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll a, b;

int main() {
  freopen("aplusb.in", "r", stdin);
  freopen("aplusb.in", "r", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> a >> b;
  if (a < b) {
    swap(a, b);
  }
  if (b > LLONG_MAX - a) {
    cout << "\"hello, %lld\\n\"";
  } else {
    cout << a + b;
  }
  return 0;
}