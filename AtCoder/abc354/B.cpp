#include <bits/stdc++.h>

using namespace std;

int n;
string s[110];
int c[110];

int main() {
  cin >> n;
  int t = 0;
  for (int i = 1; i <= n; i++) {
    cin >> s[i] >> c[i];
    t += c[i];
  }
  sort(s + 1, s + n + 1);
  cout << s[t % n + 1];
  return 0;
}