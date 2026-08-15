#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

const int maxn = 50010;

int match[maxn],zbd[maxn],ybd[maxn];
bool vis[maxn];
vector <int> G[maxn];
int n,m,e;

bool dfs(int u){
	for (int i = 0; i < G[u].size(); i++){
		int v = G[u][i];
		if (!vis[v]){
			vis[v] = 1;
			if (!match[v] || dfs(match[v])){
				match[v] = u;
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	cin >> n >> m >> e;
	for (int i = 1; i <= e; i++){
		int u,v;
		cin >> u >> v;
		G[u].push_back(v);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		memset(vis,0,sizeof(vis));
		if (dfs(i)) cnt++;
	}
	cout << cnt;
	return 0;
}