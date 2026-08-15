#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 2e5 + 10;

struct node{
    int t, x, y;
};

struct ANS{
    long long a, b;
}ans[MAXN];

vector<node> G[MAXN];
int n, m, a, b, x, y;
bool vis[MAXN];

void dfs(int u, long long x, long long y){
    if (vis[u]){
        return;
    }
    vis[u] = 1,ans[u] = {x, y};
    for (int i = 0; i < G[u].size(); i++){
        dfs(G[u][i].t, x + G[u][i].x, y + G[u][i].y);
    }
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        cin >> a >> b >> x >> y;
        G[a].push_back({b, x, y}), G[b].push_back({a, -x, -y});
    }
    dfs(1, 0, 0);
    for (int i = 1; i <= n; i++){
        !vis[i] ? cout << "undeciable\n" : cout << ans[i].a << ' ' << ans[i].b << '\n';
    }
    return 0;
}