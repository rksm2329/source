#include <iostream>

using namespace std;

string s;
bool ans;
int cnt1, cnt2, status;

int main() {
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (status) {
      if (s[i] == '(') {
        int x = 1;
        while (x) {
          i++;
          if (s[i] == '(') {
            x++;
          }
          if (s[i] == ')') {
            x--;
          }
        }
      } else if (status == 1 && s[i] == '|') {
        status = 0;
      } else if (s[i] == ')') {
        status = 0;
      } else if (status == 1 && s[i] == '&') {
        cnt1++;
      } else if (status == 2 && s[i] == '|') {
        cnt2++;
      }
    } else {
      if (s[i] == '1') {
        ans = 1;
      }
      if (s[i] == '0') {
        ans = 0;
      }
      if (s[i] == '&' && ans == 0) {
        status = 1;
        cnt1++;
      }
      if (s[i] == '|' && ans == 1) {
        status = 2;
        cnt2++;
      }
    }
  }
  cout << ans << '\n' << cnt1 << ' ' << cnt2;
  return 0;
}