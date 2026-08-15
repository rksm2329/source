#include <bits/stdc++.h>

using namespace std;

int t, n, m, p;

void Solve() {
  cin >> n >> m >> p;
  if (m - m % p == 0) {
    cout << "Alice\n";
  } else if (n - n % p == 0) {
    cout << "Bob\n";
  } else {
    cout << "Lasting Battle\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  for (cin >> t; t--; Solve()) {
  }
  return 0;
}