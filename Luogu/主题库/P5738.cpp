#include<iostream>
#include<iomanip>

using namespace std;

int n,m,x;
double ans;

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        int sum = 0,mx = 0,mi = 10;
        for (int j = 1; j <= m; j++){
            cin >> x;
            sum += x;
            mx = max(mx,x),mi = min(mi,x);
        }
        ans = max(ans,1.0 * (sum - mx - mi) / (m - 2));
    }
    cout << fixed << setprecision(2) << ans;
    return 0;
}