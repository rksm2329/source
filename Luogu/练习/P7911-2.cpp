#include <iostream>
#include <map>

using namespace std;

int n;
string s, t;
map<string, int> mp;

template <typename T> void readInt(T &x) {
  x = 0;
  T sign = 1;
  char ch = getchar();
  bool f = 0;
  for (; ch < '0' || ch > '9'; ch = getchar()) {
    f = 1;
    if (ch == '-') {
      sign = -1;
      break;
    }
  }
  if (f) {
    ch = getchar();
  }
  for (; ch >= '0' && ch <= '9';
       x = (x << 3) + (x << 1) + ch - '0', ch = getchar()) {
  }
  x *= sign;
}

template <typename T> void writeInt(T x) {
  if (x < 0) {
    putchar('-'), x = -x;
  }
  if (x <= 9) {
    putchar(x + '0');
    return;
  }
  writeInt(x / 10);
  putchar(x % 10 + '0');
}

int main() {
  readInt<int>(n);
  for (int i = 1, id = 1; i <= n; i++, id++) {
    cin >> s >> t;
    long long num = 0;
    bool f = 0;
    int c1 = 0, c2 = 0;
    if (t[0] == '.' || t[0] == ':') {
      cout << "ERR\n";
      continue;
    }
    for (int j = 0; j < t.size(); j++) {
      if (t[j] >= '0' && t[j] <= '9') {
        if ((j == 0 || t[j - 1] == '.' || t[j - 1] == ':') && t[j] == '0') {
          if (j == t.size() - 1) {
            continue;
          }
          if (t[j + 1] != '.' && t[j + 1] != ':') {
            cout << "ERR\n";
            f = 1;
            break;
          }
        }
        num = num * 10 + t[j] - '0';
      } else {
        if (t[j - 1] == '.' || t[j - 1] == ':') {
          cout << "ERR\n";
          f = 1;
          break;
        }
        c1 += t[j] == '.';
        c2 += t[j] == ':';
        if (num < 0 || num > 255) {
          cout << "ERR\n";
          f = 1;
          break;
        }
        num = 0;
      }
    }
    if (!f) {
      if (t[t.size() - 1] == '.' || t[t.size() - 1] == ':' || num < 0 ||
          num > 65535 || c1 != 3 || c2 != 1) {
        cout << "ERR\n";
        continue;
      }
      if (s == "Server") {
        if (mp[t]) {
          cout << "FAIL\n";
        } else {
          cout << "OK\n";
          mp[t] = id;
        }
      } else {
        if (!mp[t]) {
          cout << "FAIL\n";
        } else {
          writeInt<int>(mp[t]);
          cout << '\n';
        }
      }
    }
  }
  return 0;
}