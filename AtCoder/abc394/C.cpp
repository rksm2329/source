#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 3e5 + 10;

int stk[MAXN], top;
string s;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> s;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'W') {
      stk[++top] = i;
    } else if (s[i] == 'A') {
      for (int k = i; top && k == stk[top] + 1; s[stk[top]] = 'A', s[k] = 'C', top--, k--);
    }
  }
  cout << s;
  return 0;
}