#include<iostream>

using namespace std;

string s;

int main(){
    int n;
    cin >> n;
    getchar();
    getline(cin,s);
    long long now = 0,ans = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'W'){
            ans += abs(0 - now);
            now = 0;
        }
        if (s[i] == 'B'){
            ans += abs(1 - now);
            now = 1;
        }
        if (s[i] == 'R'){
            ans += abs(2 - now);
            now = 2;
        }
    }
    cout << ans;
    return 0;
}