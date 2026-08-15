#include <iostream>
#include <climits>

using namespace std;

long long ans = LLONG_MIN;
long long A, B, C, D, E, F, G, P, X1, X2, Y1, Y22;

int main() {
  cin >> A >> B >> C >> D >> E >> F >> G >> P >> X1 >> X2 >> Y1 >> Y22;
  for (int x = X1; x <= X2; x++) {
    for (int y = Y1; y <= Y22; y++) {
      long long val = ((A * x * x * x) % P + (B * y * y * y) % P + (C * x * x * y) % P + (D * x * y * y) % P + (E * x * y) % P + (F * x) % P + (G * y) % P) % P;
      ans = max(ans, val);
    }
  }
  cout << ans;
  return 0;
}