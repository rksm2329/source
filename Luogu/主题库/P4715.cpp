#include <bits/stdc++.h>

using namespace std;

const int MAXN = 130;

struct Node {
	int x, id;
} a[MAXN];

int n;

int main() {
	cin >> n;
	int x = 1 << n;
	for (int i = 1; i <= x; i++) {
		cin >> a[i].x;
		a[i].id = i;
	}
	int m = 1 << n;
	while (m > 2) {
		int q = 0;
		for (int i = 1; i <= m; i += 2) {
			if (a[i].x > a[i + 1].x) {
				a[++q] = a[i];
			} else {
				a[++q] = a[i + 1];
			}
		}
		m /= 2;
	}
	if (a[1].x > a[2].x) {
		cout << a[2].id;
	} else {
		cout << a[1].id;
	}
	return 0;
}