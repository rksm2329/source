#include <iostream>

using namespace std;

const int MAXN = 1e5 + 10;

int n, k[3], a[MAXN];
string s[MAXN];

void dfs(int x){
    if (k[0] < 0 || k[1] < 0 || k[2] < 0) {
        return;
    }
    if (x > n) {
        cout << "Yes\n";
        for (int i = 1; i <= n; i++){
            cout << s[i][a[i]] << '\n';
        }
        exit(0);
    }
    for (int i = 0; i < 2; i++) {
        a[x] = i;
        k[s[x][i] - 'A']++;
        k[s[x][!i] - 'A']--;
        dfs(x + 1);
        k[s[x][i] - 'A']--;
        k[s[x][!i] - 'A']++;
    }
}

int main(){
    cin >> n;
    for (int i = 0; i < 3; i++) {
        cin >> k[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    dfs(1);
    cout << "No";
    return 0;
}