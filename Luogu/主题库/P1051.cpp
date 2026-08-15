#include <bits/stdc++.h>

using namespace std;

int a[110];

int main() {
  int n;
  cin >> n;
  char s[30], ans[30], gb, xb;
  int mx = -10, qm, bj, lw, sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> s >> qm >> bj >> gb >> xb >> lw;
    // cout << s << endl;
    if (qm > 80 && lw >= 1) {
      a[i] += 8000;
    }
    if (qm > 85 && bj > 80) {
      a[i] += 4000;
    }
    if (qm > 90) {
      a[i] += 2000;
    }
    if (qm > 85 && xb == 'Y') {
      a[i] += 1000;
    }
    if (bj > 80 && gb == 'Y') {
      a[i] += 850;
    }
    if (a[i] > mx) {
      mx = a[i];
      strcpy(ans, s);
    }
    sum += a[i];
  }
  cout << ans << '\n' << mx << '\n' << sum;
  return 0;
}