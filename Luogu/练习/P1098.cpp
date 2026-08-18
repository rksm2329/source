#include <bits/stdc++.h>

using namespace std;

string s;
int p1, p2, p3;

int main() {
  cin >> p1 >> p2 >> p3 >> s;
  for (; s[0] == '-'; s = s.substr(1)) {
    cout << '-';
  }
  int len = s.size();
  s += '#';
  for (int i = 0; i < len; i++) {
    if (s[i] == '-') {
      if (s[i - 1] != '-') {
        continue;
      } else {
        cout << s[i];
        continue;
      }
    }
    if (s[i + 1] != '-') {
      cout << s[i];
    } else {
      if (s[i] >= '0' && s[i] <= '9') {
        if (p1 < 3) {
          if (!(s[i + 2] >= '0' && s[i + 2] <= '9')) {
            cout << s[i] << '-';
            continue;
          }
          int x = s[i] - '0', y = s[i + 2] - '0';
          if (x >= y) {
            cout << x << '-';
            continue;
          }
          cout << x;
          if (p3 == 1) {
            for (int j = x + 1; j < y; j++) {
              for (int k = 1; k <= p2; k++) {
                cout << j;
              }
            }
          } else {
            for (int j = y - 1; j > x; j--) {
              for (int k = 1; k <= p2; k++) {
                cout << j;
              }
            }
          }
        } else {
          cout << s[i];
          for (int j = s[i] + 1; j < s[i + 2]; j++) {
            for (int k = 1; k <= p2; k++) {
              cout << '*';
            }
          }
        }
      } else {
        if (s[i] >= s[i + 2]) {
          cout << s[i] << '-';
          continue;
        }
        cout << s[i];
        if (p1 == 1) {
          if (p3 == 1) {
            for (char j = s[i] + 1; j < s[i + 2]; j++) {
              for (int k = 1; k <= p2; k++) {
                cout << j;
              }
            }
          } else {
            for (char j = s[i + 2] -1; j > s[i]; j--) {
              for (int k = 1; k <= p2; k++) {
                cout << j;
              }
            }
          }
        } else if (p1 == 2) {
          if (p3 == 1) {
            for (char j = s[i] + 1; j < s[i + 2]; j++) {
              for (int k = 1; k <= p2; k++) {
                cout << char(j - 32);
              }
            }
          } else {
            for (char j = s[i + 2] - 1; j > s[i]; j--) {
              for (int k = 1; k <= p2; k++) {
                cout << char(j - 32);
              }
            }
          }
        } else {
          for (char j = s[i] + 1; j < s[i + 2]; j++) {
            for (int k = 1; k <= p2; k++) {
              cout << '*';
            }
          }
        }
      }
    }
  }
  return 0;
}