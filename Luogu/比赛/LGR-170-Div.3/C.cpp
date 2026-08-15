#include <bits/stdc++.h>

using namespace std;

int t;
long long n;

void Solve() {
  cin >> n;
  if (n % 2) {
    cout << (n ^ (n / 2));
  } else {
    cout << n;
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  for (cin >> t; t--; Solve()) {
  }
  return 0;
}