#include <iostream>
using namespace std;
int n, s, cnt;
string ans;
bool change_check(int n, int x) {
  ans = "";
  while (x >= n) {
    ans += x % n + '0';
    x /= n;
  }
  ans += x + '0';
  int l = ans.size();
  for (int i = 0, j = l - 1; i <= j; i++, j--) {
    if (ans[i] != ans[j]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  cin >> n >> s;
  for (int i = s + 1; cnt < n; i++) {
    int sum = 0;
    for (int j = 2; j <= 10; j++) {
      if (change_check(j, i)) {
        sum++;
        if (sum >= 2) {
          cout << i << '\n';
          cnt++;
          break;
        }
      }
    }
  }
  return 0;
}