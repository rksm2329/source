#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  if (n & 1) {
    for (int i = 1; i <= n >> 1; i++) {
      cout << '-';
    }
    cout << '=';
    for (int i = 1; i <= n >> 1; i++) {
      cout << '-';
    }
  } else {
    for (int i = 1; i < n >> 1; i++) {
      cout << '-';
    }
    cout << "==";
    for (int i = 1; i < n >> 1; i++) {
      cout << '-';
    }
  }
  return 0;
}