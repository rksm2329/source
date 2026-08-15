#include <iostream>
#include <string>
using namespace std;

int n;
string ans;

bool change_check(int x) {
  ans = "";
  while (x >= n) {
    ans += (x % n > 9 ? x % n - 10 + 'A' : x % n + '0');
    x /= n;
  }
  ans += (x > 9 ? x - 10 + 'A' : x + '0');
  int l = ans.size();
  for (int i = 0, j = l - 1; i <= j; i++, j--) {
    if (ans[i] != ans[j]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  cin >> n;
  for (int i = 1; i <= 300; i++) {
    if (change_check(i * i)) {
      string ans2 = ans;
      change_check(i);
      for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
      }
      cout << ' ';
      for (int i = ans2.size() - 1; i >= 0; i--) {
        cout << ans2[i];
      }
      cout << '\n';
    }
  }
  return 0;
}