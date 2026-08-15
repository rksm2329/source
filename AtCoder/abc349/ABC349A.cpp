#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n, a[MAXN];

int main() {
  cin >> n;
  int sum = 0;
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  cout << 0 - sum;
  return 0;
}