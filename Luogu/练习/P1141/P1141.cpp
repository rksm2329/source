#include<iostream>

using namespace std;

const int MAXN = 1e3 + 10;
const int dx[] = {0,0,1,-1},dy[] = {1,-1,0,0};

int Index,sum,n,m,sx,sy,v[MAXN][MAXN],ans[MAXN * MAXN];
bool a[MAXN][MAXN];
char s;

void dfs(int x,int y,bool f){
  if (x < 1 || x > n || y < 1 || y > n || v[x][y] != 0 || a[x][y] == f){
    return;
  }
  v[x][y] = Index;
  sum++;
  for (int i = 0; i < 4; i++){
    dfs(x + dx[i],y + dy[i],a[x][y]);
  }
}

int main(){
  cin >> n >> m;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      cin >> s;
      a[i][j] = (s == '1');
    }
  }
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      if (v[i][j] == 0){
        sum = 0;
        Index++;
        dfs(i,j,!a[i][j]);
        ans[Index] = sum;
      }
    }
  }
  while (m--){
    cin >> sx >> sy;
    cout << ans[v[sx][sy]] << '\n';
  }
  return 0;
}