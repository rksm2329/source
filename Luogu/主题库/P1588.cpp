#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

struct node {
  int pos, step;
} que[MAXN];

int x, y, t, head = 1, tail;
bool dis[MAXN];

void r(int pos, int step) {
	if (dis[pos] || pos > 400000 || pos < 0) {
		return ;
	}
	dis[pos] = 1;
	que[++tail] = {pos, step};
}

void Solve() {
	cin >> x >> y;
	fill(dis + 1, dis + MAXN, 0);
	head = 1, tail = 0;
	for (r(x, 0); head <= tail; ) {
		node now = que[head++];
		if (now.pos == y) {
			cout << now.step << '\n';
			break;
		}
		for (int i = 1; i <= 3; i++) {
			r((i == 1 ? now.pos + 1 : (i == 2 ? now.pos - 1 : now.pos * 2)), now.step + 1);
		}
	}
}

int main() {
	for (cin >> t; t; t--) {
		Solve();
	}
  return 0;
}