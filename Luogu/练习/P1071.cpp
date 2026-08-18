#include <iostream>
#include <string>

using namespace std;

const int MAXN = 30;

int cnt[MAXN];

int main() {
  string a, b, c;
  cin >> a >> b >> c;
  int lena = a.size(), lenb = b.size();
  if (lena != lenb) {
    cout << "Failed";
    return 0;
  }
  for (int i = 0; i < lenb; i++) {
    cnt[b[i] - 'A' + 1]++;
  }
  for (int i = 1; i <= 26; i++) {
    if (!cnt[i]) {
      cout << "Failed";
      return 0;
    }
  }
  for (int i = 1; i <= 26; i++) {
    char ch = '#';
    for (int j = 0; j < lenb; j++) {
      if (b[j] == i - 1 + 'A') {
        if (ch == '#') {
          ch = a[j];
        } else if (a[j] != ch) {
          cout << "Failed";
          return 0;
        }
      }
    }
  }
  int lenc = c.size();
  for (int i = 0; i < lenc; i++) {
    for (int j = 0; j < lena; j++) {
      if (c[i] == a[j]) {
        c[i] = b[j];
        break;
      }
    }
  }
  cout << c;
  return 0;
}