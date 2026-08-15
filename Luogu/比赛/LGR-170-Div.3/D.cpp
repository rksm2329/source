#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10, INF = 0x3f3f3f3f;

int t, n, m, a[MAXN], vis[MAXN];

void Solve() {
  cin >> n >> m;
  fill(vis, vis + n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] <= n) {
      vis[a[i]]++;
    }
  }
  int mex = -1;
  for (int i = 0; i <= n; i++) {
    if (vis[i] == 0) {
      mex = i;
      break;
    }
  }
  int mi = INF, cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] < mex && vis[a[i]] > 1) {
      mi = min(mi, a[i]);
    }
    if (a[i] > mex || vis[a[i]] > 1) {
      a[i] = mex;
      cnt++;
    }
  }
  if (!--m) {
    for (int i = 1; i <= n; i++) {
      cout << a[i] << ' ';
    }
  } else {
    if (mi != INF) {
      cnt = 0;
      for (int i = 1; i <= n; i++) {
        if (a[i] > mi || vis[a[i]] > 1) {
          a[i] = mi;
          cnt++;
        }
      }
      mex = mi;
      m--;
    }
    if (!m) {
      for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
      }
    } else {
      if (cnt > 1) {
        for (int i = 1; i <= n; i++) {
          cout << (a[i] == mex ? a[i] + m % 2 : a[i]) << ' ';
        }
      } else {
        for (int i = 1; i <= n; i++) {
          cout << a[i] << ' ';
        }
      }
    }
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  for (cin >> t; t--; Solve()) {
  }
  return 0;
}