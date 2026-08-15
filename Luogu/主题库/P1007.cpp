#include <algorithm>
#include <iostream>


using namespace std;

int l, n, x, ans, answ;

int main() {
  cin >> l >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    ans = max(ans, min(l - x + 1, x));
    answ = max(answ, max(l - x + 1, x));
  }
  cout << ans << ' ' << answ;
  return 0;
}