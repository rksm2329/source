#include<iostream>

using namespace std;

const int MAXN = 2e2 + 10,MAXV = 1e5;

int t,n,m,a[MAXN][MAXN],prime[MAXV + 10],vis[MAXV + 10],total;

void Sieve(int n){
    vis[1] = 1;
    for (int i = 2; i <= n; i++){
        if (!vis[i]){
            prime[++total] = i;
        }
        for (int j = 1; j <= total && i * prime[j] <= n; j++){
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0){
                break;
            }
        }
    }
}

int main(){
    cin >> t;
    Sieve(MAXV);
    while (t--){
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (vis[a[i][j]]){
                    cout << 0 << ' ';
                    continue;
                }
                bool f = 0;
                for (int k = 2; k <= i; k++){
                    if (vis[a[i - k + 1][j]]){
                        cout << k - 1 << ' ';
                        f = 1;
                        break;
                    }
                }
                if (!f){
                    cout << i << ' ';
                }
            }
            cout << '\n';
        }
    }
    return 0;
}