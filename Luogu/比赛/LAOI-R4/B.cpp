#include <bits/stdc++.h>

using namespace std;

int t, n;

void Solve() {
  cin >> n;
  if (n % 2 == 0) {
    for (int i = 1; i <= n / 2; i++) {
      cout << 0 << ' ';
    }
    for (int i = 1; i <= n / 2; i++) {
      cout << 1 << ' ';
    }
    return;
  }
  for (int i = 1; i <= n / 2; i++) {
    cout << 1 << ' ';
  }
  cout << 2 << ' ';
  for (int i = 1; i <= n / 2; i++) {
    cout << 0 << ' ';
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