#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
  map<int, int> a;
  set<int> b;
  int n, i, q;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> q;
    a[q]++;
    b.insert(q);
  }
  for (set<int>::iterator it = b.begin(); it != b.end(); it++) {
    cout << *it << ' ' << a[*it] << '\n';
  }
  return 0;
}