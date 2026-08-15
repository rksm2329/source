#include <cmath>
#include <iostream>

using namespace std;

int t, p, a, b, c;

void Solve() {
  cin >> p >> a >> b >> c;
  if (!c) {
    cout << "Yes\n";
    return ;
  }
  cout << ((b % p == 0 || !c) ? "No\n" : "Yes\n");
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  for (cin >> t; t--; Solve()) {
  }
  return 0;
}