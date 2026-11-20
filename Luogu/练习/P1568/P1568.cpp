#include<iostream>

using namespace std;

const int MAXN = 1e6 + 10;

int n,m,speed,t,st,p1[MAXN],p2[MAXN],flag[MAXN];

int main(){
    cin >> n >> m;
    int l = 0;
    for (int i = 1; i <= n; i++){
        cin >> speed >> t;
        st += t;
        for (int j = l + 1; j <= l + t; j++){
            p1[j] = speed;
        }
        l += t;
    }
    l = 0;
    for (int i = 1; i <= m; i++){
        cin >> speed >> t;
        for (int j = l + 1; j <= l + t; j++){
            p2[j] = speed;
        }
        l += t;
    }
    int sum1 = 0,sum2 = 0;
    long long ans = 0;
    for (int i = 1; i <= st; i++){
        sum1 += p1[i],sum2 += p2[i];
        flag[i] = (sum1 >= sum2 ? 1 : 2);
        ans += flag[i] != flag[i - 1];
    }
    cout << ans - 1;
    return 0;
}