#include<iostream>
#include<algorithm>

using namespace std;

int n,mx,cnt[110];
string name[110],s[110];

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> name[i] >> s[i];
        int pos = 0;
        while (s[i].find("sos",pos) != string::npos){
            cnt[i]++;
            pos = s[i].find("sos",pos) + 1;
        }
        mx = max(mx,cnt[i]);
    }
    for (int i = 1; i <= n; i++){
        if (cnt[i] == mx){
            cout << name[i] << ' ';
        }
    }
    cout << '\n' << mx;
    return 0;
}