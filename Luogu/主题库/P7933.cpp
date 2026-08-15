#include <iostream>

using namespace std;

int n;

int main() {
  cin >> n;
  if (n == 1) {
    cout << 0;
    return 0;
  }
  int i;
  for (i = 2; i * i <= n && n % i; i++) {
  }
  if (i * i > n) {
    cout << n - 1;
  } else {
    cout << n - n / i;
  }
  return 0;
}