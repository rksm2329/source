#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int n, a[MAXN];
int ans;
vector<pair<int, int>> v;

void Sort(int a[], int l, int r) {
  int i = l, j = r, flag = a[(l + r) / 2];
  do {
    for (; a[i] < flag; ) i++;
    for (; a[j] > flag; ) j--;
    if (i <= j) {
      swap(a[i], a[j]);
      v.push_back({i, j});
      ans++;
      i++, j--;
    }
  } while (i <= j);
  if (l < j) {
    Sort(a, l, j);
  }
  if (i < r) {
    Sort(a, i, r);
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  Sort(a, 1, n);
  for (pair<int, int> i : v) {
    if (i.first == i.second) {
      ans--;
    }
  }
  cout << ans << '\n';
  for (pair<int, int> i : v) {
    if (i.first == i.second) {
      continue;
    }
    cout << i.first << ' ' << i.second << '\n';
  }
  return 0;
}