#include<iostream>

using namespace std;

const int MAXN = 1e5 + 10,MOD = 1e9 + 7;

int n,ans = 1;
long long tmp[3];

int main(){
    cin >> n;
    for (int i = 1,x; i <= n; i++){
        cin >> x;
        int f = 0,position = 0;
        if (x == tmp[0]){
            f++;
            position = 0;
        }
        if (x == tmp[1]){
            f++;
            position = 1;
        }
        if (x == tmp[2]){
            f++;
            position = 2;
        }
        ans = ans * f % MOD;
        tmp[position]++;
    }
    cout << ans;
    return 0;
}