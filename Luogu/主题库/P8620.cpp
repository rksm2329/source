#include <bits/stdc++.h>

using namespace std;

string s, k;
int a[20];

int main() {
  cin >> s;
  for (int i = 1; i <= s.size(); i++) {
    a[i] = i;
  }
  for (int i = 0; i < s.size(); i++) {
    k += i + 'a';
  }
  int ans = 0;
  do {
    string t = "";
    for (int i = 1; i <= s.size(); i++) {
      t += k[a[i] - 1];
    }
    if (t == s) {
      cout << ans;
      return 0;
    }
    ans++;
  } while (next_permutation(a + 1, a + s.size() + 1));
  return 0;
}