#include <bits/stdc++.h>

using namespace std;

const int MAXV = 25e4 + 10, MAXN = 1e6 + 10;

int n, g;
int fr[MAXV];
int siz[MAXV];
pair<int, int> pos[MAXV];
int cow[MAXV], cows;
bool used[MAXV], inv[MAXN];

int main() {
  cin >> n >> g;
  for (int i = 1; i <= g; i++) {
    cin >> siz[i];
    for (int j = 1; j <= siz[i]; j++) {
      cin >> cow[++cows];
    }
    pos[i].first = pos[i - 1].second + 1;
    pos[i].second = pos[i - 1].second + siz[i];
  }
  inv[1] = 1;
  bool invi;
  do {
    invi = 0;
    for (int i = 1; i <= g; i++) {
      if (!used[i]) {
        int cnt = 0;
        for (int j = pos[i].first; j <= pos[i].second; j++) {
          cnt += inv[cow[j]];
        }
        if (cnt == siz[i] - 1) {
          used[i] = 1;
          invi = 1;
          for (int j = pos[i].first; j <= pos[i].second; j++) {
            inv[cow[j]] = 1;
          }
        } else if (cnt == siz[i]) {
          used[i] = 1;
        }
      }
    }
  } while (invi);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += inv[i];
  }
  cout << ans;
  return 0;
}