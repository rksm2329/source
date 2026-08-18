#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

struct Node {
  int t, id;
} a[MAXN];

int n, m, t;
vector<int> v[MAXN];

bool cmp(const Node &i, const Node &j) {
  if (i.id != j.id) {
    return i.id < j.id;
  } else {
    return i.t < j.t;
  }
}

int main() {
  cin >> n >> m >> t;
  for (int i = 1; i <= m; i++) {
    cin >> a[i].t >> a[i].id;
  }
  sort(a + 1, a + m + 1, cmp);
  int indx = 0;
  for (int i = 1; i <= m; i++) {
    if (a[i].id != a[i - 1].id) {
      indx += (a[i].id - a[i - 1].id);
    }
    v[indx].push_back(a[i].t);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (v[i].size() == 0) {
      continue;
    }
    int tjd = 0;
    bool isyx = 0;
    for (int j = 0; j < v[i].size(); j++) {
      if (j == 0 || v[i][j] != v[i][j - 1]) {
        if (j) {
          tjd = max(0, tjd - (v[i][j] - v[i][j - 1] - 1));
        }
        if (isyx && tjd <= 3) {
          isyx = 0;
        } else if (tjd > 5) {
          isyx = 1;
        }
      }
      tjd += 2;
    }
    if (isyx && tjd <= 3) {
      isyx = 0;
    } else if (tjd > 5) {
      isyx = 1;
    }
    if (v[i][v[i].size() - 1] != t) {
      tjd = max(0, tjd - (t - v[i][v[i].size() - 1]));
      if (isyx && tjd <= 3) {
        isyx = 0;
      }
    }
    ans += isyx;
  }
  cout << ans;
  return 0;
}