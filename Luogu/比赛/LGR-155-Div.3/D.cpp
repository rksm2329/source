#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 1e3 + 10;

int n,m,c1,c2,mx,ans,a[MAXN],b[MAXN],dp[MAXN][MAXN];

int main(){
    cin >> n >> m >> c1 >> c2;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++){
        cin >> b[i];
    }
    for (int k = 1; k <= n; k++){
        
    }
    cout << mx << ' ' << ans;
    return 0;
}