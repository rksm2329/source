#include<iostream>

using namespace std;

const int MAXN = 1e3 + 10,MAXW = 1e4 + 10,MOD = 1e9 + 7;

int n,w,a[MAXN],dp[MAXW];

int main(){
  cin >> n >> w;
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  dp[0] = 1;
  for (int i = 1; i <= w; i++){
    for (int j = 1; j <= n; j++){
      if (i >= a[j]){
        dp[i] = (dp[i] + dp[i - a[j]]) % MOD;
      }
    }
  }
  cout << dp[w];
  return 0;
}