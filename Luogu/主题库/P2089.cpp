#include<iostream>

using namespace std;

const int MAXN = 5e4 + 10;

int n,ans,a[MAXN][20],b[20];

void dfs(int x,int sum){
  if (x == 11 && sum == n){
    for (int i = 1; i <= 10; i++){
      a[ans][i] = b[i];
    }
    ans++;
    return;
  }
  if (x > 11 || sum > n){
    return;
  }
  for (int i = 1; i <= 3; i++){
    b[x] = i;
    dfs(x + 1,sum + i);
  }
}

int main(){
  cin >> n;
  if (n > 30){
    cout << 0;
    return 0;
  }
  dfs(1,0);
  cout << ans << '\n';
  for (int i = 0; i < ans; i++){
    for (int j = 1; j <= 10; j++){
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}