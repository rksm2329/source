#include<bits/stdc++.h>

using namespace std;

int t,m,n,ans;

void dfs(int x,int y,int last){
  if (y > m || x > n){
    return;
  }
  if (y == m && x <= n){
    ans++;
    return;
  }
  for (int i = last; i <= m; i++){
    dfs(x + 1,y + i,i);
  }
}

int main(){
  cin >> t;
  while (t--){
     ans = 0;
     cin >> m >> n;
     dfs(0,0,1);
     cout << ans << '\n';
  }
  return 0;
}