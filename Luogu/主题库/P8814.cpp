#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

long long t,n,d,e;

int main(){
    cin >> t;
    while (t--){
        cin >> n >> d >> e;
        long long t1 = sqrt((n - d * e + 2) * (n - d * e + 2) - (n * 4));
        long long t2 = n - d * e + 2;
        long long p = (t1 + t2) >> 1;
        long long q = t2 - p;
        if (p * q == n && d * e == (p - 1) * (q - 1) + 1 && p && q){
            cout << min(p,q) << ' ' << max(p,q) << '\n';
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}