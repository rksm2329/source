#include <bits/stdc++.h>

using namespace std;

int k;
long long n, d, e;

long long F() {
  long long m = n - e * d + 2;
  long long l = 1, r = m / 2;
  while (l < r) {
    long long mid = (l + r) >> 1;
    long long p = mid, q = m - mid;
    (p * q >= n ? r = mid : l = mid + 1);
  }
  return (l * (m - l) == n ? l : -1);
}

void Solve() {
  cin >> n >> d >> e;
  long long x = F();
  long long m = n - e * d + 2;
  if (x == -1) {
    cout << "NO\n";
  } else {
    cout << x << ' ' << m - x << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  for (cin >> k; k--; Solve()) {
  }
  return 0;
}