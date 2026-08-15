#include <algorithm>
#include <iostream>
#include <map>


using namespace std;

string s;
map<string, int> p;
int a[7], cnt;

int main() {
  p["one"] = 1, p["two"] = 2, p["three"] = 3, p["four"] = 4, p["five"] = 5,
  p["six"] = 6, p["seven"] = 7, p["eight"] = 8, p["nine"] = 9, p["ten"] = 10,
  p["eleven"] = 11, p["twelve"] = 12, p["thirteen"] = 13, p["fourteen"] = 14,
  p["fifteen"] = 15, p["sixteen"] = 16, p["seventeen"] = 17, p["eighteen"] = 18,
  p["ninety"] = 19, p["twenty"] = 20, p["a"] = 1, p["both"] = 2,
  p["another"] = 1, p["first"] = 1, p["second"] = 2, p["third"] = 3;
  while (cin >> s) {
    if (p[s]) {
      if (p[s] * p[s] % 100 == 0) {
        continue;
      }
      a[++cnt] = p[s] * p[s] % 100;
    }
  }
  sort(a + 1, a + cnt + 1);
  cout << a[1];
  for (int i = 2; i <= cnt; i++) {
    cout << a[i] / 10 << a[i] % 10;
  }
  return 0;
}