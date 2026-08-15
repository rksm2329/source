#include<iostream>

using namespace std;

int n,a,b;
string s;

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> s >> a >> b;
        cout << s << ' ' << a + 1 << ' ' << min(b + b / 5,600) << '\n';
    }
    return 0;
}