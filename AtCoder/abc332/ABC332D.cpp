#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10;

int a[MAXN][MAXN], b[MAXN][MAXN], v1[MAXN], v2[MAXN], n, m,
    ans = INT_MAX, t1[MAXN], t2[MAXN];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> b[i][j];
    }
  }
  for (int i = 1; i <= n; i++) v1[i] = i;
  do {
    for (int i = 1; i <= m; i++) v2[i] = i;
    do {
      int cnt = 0;
      bool flag = 0;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          if (a[v1[i]][v2[j]] != b[i][j]) {
            flag = 1;
          }
        }
      }
      if (!flag) {
        for (int i = 1; i <= n; i++) t1[i] = v1[i];
        for (int i = 1; i <= m; i++) t2[i] = v2[i];
        for (int i = 1; i <= n; i++) {
          for (int j = 1; j < n; j++) {
            if (v1[j] > v1[j + 1]) swap(v1[j], v1[j + 1]), cnt++;
          }
        }
        for (int i = 1; i <= m; i++) {
          for (int j = 1; j < m; j++) {
            if (v2[j] > v2[j + 1]) swap(v2[j], v2[j + 1]), cnt++;
          }
        }
        for (int i = 1; i <= n; i++) v1[i] = t1[i];
        for (int i = 1; i <= m; i++) v2[i] = t2[i];
        ans = min(ans, cnt);
      }
    } while (next_permutation(v2 + 1, v2 + m + 1));
  } while (next_permutation(v1 + 1, v1 + n + 1));
  cout << (ans == INT_MAX ? -1 : ans);
  return 0;
}