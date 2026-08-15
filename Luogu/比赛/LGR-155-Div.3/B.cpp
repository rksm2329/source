#include<iostream>
#include<string>

using namespace std;

const int MAXN = 1e6 + 10;

int n,m,tot,cnt,last,ans[MAXN];
string s;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m >> s;
    if (s[0] == 'Y'){
        cout << "No solution";
        return 0;
    }

    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'N'){
            ans[++tot] = ++cnt;
            if (cnt > n){
                cout << "No solution";
                return 0;
            }
            if (!last){
                last = cnt;
            }
        }
        else {
            ans[++tot] = last;
        }
    }

    for (int i = 1; i <= m; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}