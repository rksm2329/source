#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;

bool Check(char a, char b) {
  return (a == 'A' && b == 'T') || (a == 'T' && b == 'A') || (a == 'C' && b == 'G') || (a == 'G' && b == 'C');
}

bool Legit(char c) {
  return c == 'A' || c == 'T' || c == 'C' || c == 'G';
}

void Solve() {
  cin >> n >> s;
  string t = s;
  reverse(t.begin(), t.end());
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (Check(s[i], t[i])) {
      ans += i + 1;
    }
    if (!Legit(s[i]) || !Legit(t[i])) {
      ans = 0;
      break;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  for (cin >> t; t; t--) {
    Solve();
  }
  return 0;
}