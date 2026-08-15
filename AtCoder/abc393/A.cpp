#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string s, t;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> s >> t;
  if (s == "sick" && t == "sick") {
    cout << 1;
  } else if (s == "sick") {
    cout << 2;
  } else if (t == "sick") {
    cout << 3;
  } else {
    cout << 4;
  }
  return 0;
}