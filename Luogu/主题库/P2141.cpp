#include<iostream>

using namespace std;

const int MAXN = 2e5 + 10;

int t[MAXN],g[MAXN];
int n,a[105],ans;

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        g[a[i]] = 1;
    }
    for (int i = 1; i < n; i++){
        for (int j = i + 1; j <= n; j++){
            t[a[i] + a[j]]++;
        }
    }
    for (int i = 1; i < MAXN; i++){
        if (t[i] > 0 && g[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}
