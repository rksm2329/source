#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int n, a, b, d[MAXN];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
    d[i] %= (a + b);
  }
  sort(d + 1, d + n + 1);
  if (d[n] - d[1] + 1 > a) {
    cout << "No";
  } else {
    cout << "Yes";
  }
  return 0;
}