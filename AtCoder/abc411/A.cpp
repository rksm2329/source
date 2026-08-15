#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string s;
int l;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> s >> l;
  cout << (s.size() >= l ? "Yes" : "No");
  return 0;
}