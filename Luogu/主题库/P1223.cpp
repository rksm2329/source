#include <algorithm>
#include <iomanip>
#include <iostream>


using namespace std;

const int MAXN = 1e3 + 10;

struct node {
  int x, id;
} t[MAXN];

int n;
double ans;

bool cmp(const node &i, const node &j) { return i.x < j.x; }

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t[i].x;
    t[i].id = i;
  }
  sort(t + 1, t + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    cout << t[i].id << ' ';
    ans += t[i].x * (n - i);
  }
  cout << '\n' << fixed << setprecision(2) << ans / n;
  return 0;
}