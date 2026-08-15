#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n,m,ans,a[MAXN];

int main(){
  cin >> n >> m;
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  int sum = 0;
  for (int i = 1; i <= n; i++){
    if (sum + a[i] <= m){
      sum += a[i];
    }
    else {
      sum = a[i];
      ans++;
    }
  }
  if (sum){
    ans++;
  }
  cout << ans;
  return 0;
}