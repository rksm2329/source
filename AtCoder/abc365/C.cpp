#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
const long long INF = 4e14;

int n;
long long m;
long long a[MAXN];

bool C(long long x) {
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += min(x, a[i]);
  }
  return sum <= m;
}

long long F() {
  long long l = 0, r = INF;
  while (l < r) {
    long long mid = (l + r + 1) >> 1;
    if (C(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  return l;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long ans = F();
  if (ans == INF) {
    cout << "infinite";
  } else {
    cout << ans;
  }
  return 0;
}