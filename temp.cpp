#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) p << 1
#define rs(p) p << 1 | 1
#define lowbit(p) p&(-p)

const int N = 1e6 + 5;
const int P = 1e9 + 7;
const int INF = 1e18;

int n, a[N], ans;
int f[N][2], F[N][2], h[N], H[N];
vector <int> G[N];

void dfs1 (int u, int fa) {
	f[u][0] = 0; h[u] = 1;
	f[u][1] = a[u];
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfs1(v, u);
		f[u][0] += max(f[v][0], f[v][1]);
		f[u][1] += f[v][0];
		h[u] += (f[v][0] < f[v][1]) * h[v];
	}
}

void dfs2 (int u, int fa) {
	if (u == 1) {
		F[u][0] = f[u][0];
		F[u][1] = f[u][1];
		H[u] = h[u];
	}
	for (auto v : G[u]) {
		if (v == fa) continue;
		
		int res0 = F[u][0] - max(f[v][0], f[v][1]);
		int res1 = F[u][1] - f[v][0];
		F[v][0] = f[v][0] + max(res0, res1);
		F[v][1] = f[v][1] + res0;
		
		H[v] = h[v];
		if (res0 < res1) H[v] += H[u],
			H[v] -= (f[v][0] < f[v][1]) * h[v];
		
		dfs2(v, u);
	}
}

void solve () {
	cin >> n; ans = 0;
	for (int i = 1; i <= n; i++) G[i].clear();
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	for (int i = 1; i <= n; i++)
		if (F[i][0] != F[i][1]) ans = max(ans, H[i]);
	cout << ans << "\n";
}

signed main () {
	freopen("tree9.in", "r", stdin);
//	freopen("tree.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 1; cin >> T;
	while(T--) solve();
	return 0;
}
