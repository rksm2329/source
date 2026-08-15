#include <bits/stdc++.h>

using namespace std;

int n;
long long t;
string s;
vector<long long> x1, x2;

int main() {
  cin >> n >> t >> s;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    if (s[i] == '1') {
      x1.push_back(x);
    } else {
      x2.push_back(x);
    }
  }
  sort(x1.begin(), x1.end());
  sort(x2.begin(), x2.end());
  int l = 0, r = 0;
  long long ans = 0;
  for (int i = 0; i < x1.size(); i++) {
    for (; l < x2.size() && x2[l] < x1[i]; l++);
    for (; r < x2.size() && x2[r] <= x1[i] + 2 * t; r++);
    ans += r - l;
  }
  cout << ans;
  return 0;
}