#include<iostream>

using namespace std;

int n;
char op;
string x;
int a,b;

int len(int x){
    if (x == 0){
        return 1;
    }
    int ans = 0;
    for (; x; x /= 10,ans++){
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> x;
        if (x[0] >= '0' && x[0] <= '9'){
            a = 0;
            for (int j = 0; j < x.size(); j++){
                a = a * 10 + x[j] - '0';
            }
            cin >> b;
        }
        else {
            cin >> a >> b;
            op = x[0];
        }
        if (op == 'a'){
            cout << a << '+' << b << '=' << a + b << '\n' << len(a) + len(b) + len(a + b) + 2 << '\n';
        }
        else if (op == 'b'){
            cout << a << '-' << b << '=' << a - b << '\n';
            int ans = len(a) + len(b) + len(a - b) + 2;
            if (a - b < 0){
                ans++;
            }
            cout << ans << '\n';
        }
        else {
            cout << a << '*' << b << '=' << a * b << '\n' << len(a) + len(b) + len(a * b) + 2 << '\n';
        }
    }
    return 0;
}