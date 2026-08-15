#include<iostream>
#include<cmath>

using namespace std;

const int MAXN = 2e2 + 10;

int cnt = 1,n,ans[MAXN * MAXN];
char a,b = '0';

int main(){
    while (cin >> a){
        n++;
        if (a == b){
            ans[cnt]++;
        }
        else {
            ans[++cnt]++;
            b = a;
        }
    }
    cout << sqrt(n) << ' ';
    for (int i = 1; i <= cnt; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}