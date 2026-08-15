#include<iostream>
#include<map>

using namespace std;

const int MAXN = 5e4 + 10;

int t,n,tot,a[MAXN];
map<int,bool> cnt;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            if (!cnt[a[i]]){
                cout << a[i] << ' ';
            }
            cnt[a[i]] = 1;
        }
        cnt.clear();
        cout << '\n';
    }
    return 0;
}