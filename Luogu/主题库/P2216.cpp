#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 10;

int n, m, k, ans = INT_MAX, a[MAXN][MAXN], r1[MAXN][MAXN], r2[MAXN][MAXN], r3[MAXN][MAXN], r4[MAXN][MAXN];

int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int x = 1; x <= n; x++) {
    deque<int> que1, que2;
    for (int i = 1; i <= m; i++) {
      if (que1.front() + k - 1 < i) {
        que1.pop_front();
      }
      for (; !que1.empty() && a[x][que1.back()] <= a[x][i]; que1.pop_back()) {
      }
      que1.push_back(i);
      r1[x][i] = a[x][que1.front()];
      if (que2.front() + k - 1 < i) {
        que2.pop_front();
      }
      for (; !que2.empty() && a[x][que2.back()] >= a[x][i]; que2.pop_back()) {
      }
      que2.push_back(i);
      r3[x][i] = a[x][que1.front()];
    }
  }
  for (int x = 1; x <= m; x++) {
    deque<int> que1, que2;
    for (int i = 1; i <= n; i++) {
      if (que1.front() + k - 1 < i) {
        que1.pop_front();
      }
      for (; !que1.empty() && r1[que1.back()][x] <= r1[i][x]; que1.pop_back()) {
      }
      que1.push_back(i);
      r2[i][x] = r1[que1.front()][x];
      if (que2.front() + k - 1 < i) {
        que2.pop_front();
      }
      for (; !que2.empty() && r3[que2.back()][x] >= r3[i][x]; que2.pop_back()) {
      }
      que2.push_back(i);
      r4[i][x] = r3[que2.front()][x];
    }
  }
  for (int i = k; i <= n; i++) {
    for (int j = k; j <= m; j++) {
      ans = min(ans, r2[i][j] - r4[i][j]);
    }
  }
  cout << ans;
  return 0;
}