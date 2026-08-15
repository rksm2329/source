#include <algorithm>
#include <iostream>


using namespace std;

int t;
long long n;

int main() {
  for (cin >> t; t; t--) {
    cin >> n;
    if (__builtin_popcountll(n) >= 3) {
      cout << "No,Commander\n";
    } else if (__builtin_popcountll(n) == 1) {
      cout << n + 1 << '\n';
    } else {
      cout << n + (n & -n) << '\n';
    }
  }
  return 0;
}