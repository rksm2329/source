#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int n;
long long l1, l2;
pair<int, int> a[MAXN], b[MAXN];

bool cmp1(const pair<int, int> &i, const pair<int, int> &j) {
  return i.first > j.first;
}

bool cmp2(const pair<int, int> &i, const pair<int, int> &j) {
  return i.second > j.second;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> l1 >> l2;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i].second;
    b[i] = a[i];
  }
  sort(a + 1, a + n + 1, cmp1);
  sort(b + 1, b + n + 1, cmp2);
  int c1, c2;
  long long s1 = 0, s2 = 0;
  for (c1 = 1; c1 <= n; c1++) {
    s1 += a[c1].first;
    s2 += a[c1].second;
    if (s1 > l1 || s2 > l2) {
      break;
    }
  }
  s1 = 0, s2 = 0;
  for (c2 = 1; c2 <= n; c2++) {
    s1 += b[c2].first;
    s2 += b[c2].second;
    if (s1 > l1 || s2 > l2) {
      break;
    }
  }
  c1 = min(c1, n);
  c2 = min(c2, n);
  cout << min(c1, c2);
  return 0;
}