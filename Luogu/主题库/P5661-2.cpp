#include<iostream>

using namespace std;

const int MAXN = 1e5 + 10;

struct node{
    int p,t,f;
}a[MAXN];

int n,p,t,total,ans;
bool op;

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> op >> p >> t;
        if (op == 0){
            a[++total] = {p,t,0};
            ans += p;
        }
        else {
            bool flag = 0;
            for (int j = max(1,total - 45); j <= total; j++){
                if (t - a[j].t && t - a[j].t <= 45 && a[j].p >= p && !a[j].f){
                    flag = 1;
                    a[j].f = 1;
                    break;
                }
            }
            if (!flag){
                ans += p;
            }
        }
    }
    cout << ans;
    return 0;
}