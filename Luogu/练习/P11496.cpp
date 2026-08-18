#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 2e18;

ll k;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> k;
  ll sum = 0, ans = INF;
  if (k == 0) {
    cout << 0;
    return 0;
  } else if (k > 0) {
    for (ll i = 1; ; i += 2) {
      sum += i;
      if (sum > k) {
        break;
      } else if ((k - sum) % ((i + 1) / 2) == 0 && ((k - sum) / ((i + 1) / 2)) % 2 == 0) {
        ll ed = i + (k - sum) / ((i + 1) / 2);
        ans = min(ans, (ed + 1) / 2);
      }
    }
  } else {
    k = abs(k);
    for (ll i = 1; ; i += 2) {
      sum += i;
      if (sum > k) {
        break;
      } else if ((k - sum) % ((i + 1) / 2) == 0 && ((k - sum) / ((i + 1) / 2)) % 2 == 0) {
        ll st = 1 + (k - sum) / ((i + 1) / 2);
        st = max(0ll, st - 2);
        ans = min(ans, (st + 1) / 2);
      }
    }
  }
  if (ans == INF) {
    cout << "none";
  } else {
    cout << ans;
  }
  return 0;
}