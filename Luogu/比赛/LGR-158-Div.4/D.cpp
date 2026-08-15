#include<iostream>

using namespace std;

const int MAXN = 1e6 + 10;

int n,m,ans,s[MAXN],w[MAXN];

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> s[i];
    }
    for (int i = 1; i <= m; i++){
        cin >> w[i];
        if (w[i] <= n && s[w[i]] < 200){
            ans++;
        }
    }
    cout << ans;
    return 0;
}