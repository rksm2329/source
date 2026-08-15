#include<bits/stdc++.h>

using namespace std;

string s1, s2;

void dfs(int l, int r, int s) {
	cout << s2[r - s];
	for (int i = l; i <= r; i++) {
		if (s1[i] == s2[r - s]) {
			if (i != l) {
				dfs(l, i - 1, s);
			}
			if (i != r) {
				dfs(i + 1, r, s + 1);
			}
		}
	}
}

int main(){
	cin >> s1 >> s2;
	int l = s1.size() - 1;
	dfs(0, l, 0);
	return 0;
}