#include<iostream>

using namespace std;

const int MAXN = 1e5 + 10;

struct node{
    int v,t;
}a[MAXN];

int n,t,x,cnt[MAXN];
long long mx;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> t;
    for (int i = 1; i <= n; i++){
        cin >> a[i].v >> a[i].t;
        cnt[i] = (t - a[i].t) * a[i].v;
        if (cnt[i] > mx){
            mx = cnt[i];
        }
    }
    for (int i = 1; i <= n; i++){
        if (cnt[i] == mx){
            cout << i;
            return 0;
        }
    }
    return 0;
}