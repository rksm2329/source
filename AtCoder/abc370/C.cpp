#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

string s, t;
int tot1, tot2;
pair<char, int> a[MAXN], b[MAXN];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> s >> t;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != t[i]) {
      if (s[i] > t[i]) {
        a[++tot1] = {t[i], i};
      } else {
        b[++tot2] = {t[i], i};
      }
    }
  }
  cout << tot1 + tot2 << '\n';
  for (int i = 1; i <= tot1; i++) {
    s[a[i].second] = a[i].first;
    cout << s << '\n';
  }
  for (int i = tot2; i >= 1; i--) {
    s[b[i].second] = b[i].first;
    cout << s << '\n';
  }
  return 0;
}