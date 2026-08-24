#include <bits/extc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2050;

int n, p[MAXN];
int memo[MAXN][MAXN];
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int qor(int x, int y) {
  if (x > y) swap(x, y);
  if (memo[x][y] != -1) return memo[x][y];
  cout << "? " << x << ' ' << y << "\n";
  cout.flush();
  int res;
  cin >> res;
  if (res == -1) exit(0);
  return memo[x][y] = res;
}

int qval(int x) {
  int ans = 2047;
  for (int i = 1; i <= 15; i++) {
    int k;
    do {
      k = rnd() % n + 1;
    } while (k == x);
    ans &= qor(k, x);
  }
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  memset(memo, -1, sizeof(memo));
  cin >> n;
  iota(p + 1, p + n + 1, 1);
  shuffle(p + 1, p + n + 1, rnd);
  int val = qval(p[1]), pos = p[1];
  for (int i = 2; i <= n && val; i++) {
    if (qor(pos, p[i]) == val) {
      pos = p[i];
      val = qval(pos);
    }
  }
  vector<int> res;
  for (int i = 1; i <= n; i++) {
    res.push_back(i != pos ? qor(i, pos) : 0);
  }
  cout << "! ";
  for (int x : res) cout << x << ' ';
  cout.flush();
  return 0;
}