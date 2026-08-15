#include <algorithm>
#include <iostream>


using namespace std;

const int MAXN = 30;

int n;
string s[MAXN];

bool cmp(const string &i, const string &j) { return (i + j > j + i); }

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  sort(s + 1, s + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    cout << s[i];
  }
  return 0;
}