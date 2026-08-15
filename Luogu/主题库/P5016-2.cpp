#include<iostream>
#include<climits>

using namespace std;

const int MAXN = 1e5 + 10;

long long n,m,p1,s1,s2,c[MAXN];

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> c[i];
    }
    cin >> m >> p1 >> s1 >> s2;
    c[p1] += s1;
    long long sum1 = 0,sum2 = 0;
    for (int i = 1; i <= n; i++){
        if (i < m){
            sum1 += c[i] * (m - i);
        }
        else if (i > m){
            sum2 += c[i] * (i - m);
        }
    }
    if (sum1 < sum2){
        long long mi = LLONG_MAX;
        for (int i = 1; i <= m; i++){
            mi = min(mi,abs(sum1 + s2 * (m - i) - sum2));
        }
        for (int i = 1; i <= m; i++){
            if (abs(sum1 + s2 * (m - i) - sum2) == mi){
                cout << i;
                return 0;
            }
        }
    }
    else if (sum1 > sum2){
        long long mi = LLONG_MAX;
        for (int i = m; i <= n; i++){
            mi = min(mi,abs(sum2 + s2 * (i - m) - sum1));
        }
        for (int i = m; i <= n; i++){
            if (abs(sum2 + s2 * (i - m) - sum1) == mi){
                cout << i;
                return 0;
            }
        }
    }
    else {
        cout << m;
    }
    return 0;
}