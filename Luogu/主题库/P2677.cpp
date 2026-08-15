// O(2 ^ n)
#include<iostream>

using namespace std;

int n,b,a[30],mi = 1ll << 31;

void dfs(int t,int m){ // 状态：t 为当前奶牛，m 为当前奶牛的总高度，转移：如果下一头奶牛加入奶牛塔，那么(t,m) -> (t + 1,m + a[t])，否则(t,m) -> (t + 1,m)
  if (m >= b){
    mi = min(mi,m - b);
    return;
  }
  if (t == n + 1){
    return;
  }
  dfs(t + 1,m + a[t]), dfs(t + 1,m);
}

int main(){
  cin >> n >> b;
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  dfs(1,0);
  cout << mi;
  return 0;
}