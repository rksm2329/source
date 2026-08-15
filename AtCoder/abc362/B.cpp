#include <bits/stdc++.h>

using namespace std;

int dist(int x1, int y1, int x2, int y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
  int x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  int d1 = dist(x1, y1, x2, y2);
  int d2 = dist(x1, y1, x3, y3);
  int d3 = dist(x2, y2, x3, y3);
  if (d1 + d2 == d3 || d1 + d3 == d2 || d2 + d3 == d1) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  return 0;
}