#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int n, a[MAXN], stk[MAXN], top, mx[MAXN], d[MAXN];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    while (top && a[i] > a[stk[top]]) {
      top--;
    }
    mx[i] = stk[top];
    stk[++top] = i;
  }
  for (int i = 1; i <= n; i++) {
    d[mx[i]]++, d[i]--;
  }
  for (int i = 1; i <= n; i++) {
    d[i] += d[i - 1];
    cout << d[i] << ' ';
  }
  return 0;
}