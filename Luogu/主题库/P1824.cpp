#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

int n, c, a[MAXN];

bool C(int x) {
  int ans = 1, left = a[1];
  for (int i = 2; i <= n; i++) {
    if (a[i] - left >= x) {
      ans++;
      left = a[i];
    }
  }
  return ans >= c;
}

long long F() {
  long long l = 1, r = 1e9;
  while (l < r) {
    long long mid = (l + r + 1) / 2;
    C(mid) ? l = mid : r = mid - 1;
  }
  return l;
}

int main() {
  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  cout << F();
  return 0;
}