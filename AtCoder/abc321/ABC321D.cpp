#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 2e5 + 10;

int n,m,p,a[MAXN],b[MAXN];
long long sum[MAXN];

int main(){
  cin >> n >> m >> p;
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++){
    cin >> b[i];
  }
  sort(b + 1,b + m + 1);
  for (int i = 1; i <= m; i++){
    sum[i] = sum[i - 1] + b[i];
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++){
    int x = lower_bound(b + 1,b + m + 1,p - a[i] + 1) - b - 1;
    ans += 1ll * a[i] * x + sum[x] + 1ll * p * (m - x);
  }
  cout << ans;
  return 0;
}