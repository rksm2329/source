#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 3e5, B = 550, INF = 1e9;

int n, nxt1[N + 10], nxt2[B + 10], ans[B + 10];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  fill(nxt1 + 1, nxt1 + N + 1, INF);
  fill(nxt2 + 1, nxt2 + B + 1, INF);
  fill(ans + 1, ans + B + 1, INF);
  for (char op; n--; ) {
    cin >> op;
    if (op == 'A') {
      int x;
      cin >> x;
      int blk = (x - 1) / B + 1;
      for (int i = (blk - 1) * B + 1; i <= x; i++) nxt1[i] = min(nxt1[i], x);
      for (int i = 1; i < blk; i++) nxt2[i] = min(nxt2[i], x);
      for (int i = 1; i <= B; i++) ans[i] = min(ans[i], x % i);
    } else {
      int y;
      cin >> y;
      if (y <= B) cout << ans[y] << '\n';
      else {
        int res = min(nxt1[1], nxt2[1]);
        for (int i = 1; i <= B && i * y <= N; i++) {
          int blk = (i * y - 1) / B + 1;
          int p = nxt1[i * y], q = nxt2[blk];
          if (p != INF) res = min(res, p % y);
          if (q != INF) res = min(res, q % y);
        }
        cout << res << '\n';
      }
    }
  }
  return 0;
}