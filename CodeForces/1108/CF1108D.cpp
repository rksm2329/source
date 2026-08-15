#include<iostream>

using namespace std;

string s;
int n,cnt;

int main(){
    cin >> n >> s;
    for (int i = 1; i < n; i++){
        if (s[i - 1] == s[i]){
            if (s[i - 1] != 'R' && s[i + 1] != 'R'){
                s[i] = 'R';
                cnt++;
                continue;
            }
            if (s[i - 1] != 'G' && s[i + 1] != 'G'){
                s[i] = 'G';
                cnt++;
                continue;
            }
            if (s[i - 1] != 'B' && s[i + 1] != 'B'){
                s[i] = 'B';
                cnt++;
                continue;
            }
        }
    }
    cout << cnt << '\n' << s;
    return 0;
}