#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, M = 2e3 + 10;

int mlen = 0x7fffffff, ml, mr;

int pos[M];

int pic[N], l = 1, cnt;

int main() {

  ios::sync_with_stdio(false);

  int n, m;

  cin >> n >> m;

  int na;

  memset(pos, -1, sizeof(pos));

  for (int i = 1; i <= n; i++) {

    cin >> pic[i];

    if (pos[pic[i]] == -1)
      cnt++;

    pos[pic[i]] = i;

    while (l != i && l < pos[pic[l]])
      l++;

    if (cnt == m && i - l + 1 < mlen)

      mlen = i - l + 1, ml = l, mr = i;
  }

  cout << ml << ' ' << mr << endl;

  return 0;
}