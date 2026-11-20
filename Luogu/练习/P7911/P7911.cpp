#include <iostream>
#include <unordered_map>

using namespace std;

int n;
string s, t;
unordered_map<string, int> mp;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
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
          mp[t] = i;
        }
      } else {
        if (!mp[t]) {
          cout << "FAIL\n";
        } else {
          cout << mp[t] << '\n';
        }
      }
    }
  }
  return 0;
}