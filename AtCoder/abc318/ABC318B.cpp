#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

const int MAXN = 1e2 + 10;

int n,a,b,c,d,ans;
bool cnt[MAXN][MAXN];

int main(){
    cin >> n;
    while (n--){
        cin >> a >> b >> c >> d;
        for (int i = min(a,b); i < max(a,b); i++){
            for (int j = min(c,d); j < max(c,d); j++){
                cnt[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < MAXN; i++){
        for (int j = 0; j < MAXN; j++){
            ans += cnt[i][j];
        }
    }
    cout << ans;
    return 0;
}