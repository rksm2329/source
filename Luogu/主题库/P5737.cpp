#include<iostream>

using namespace std;

const int MAXN = 3e3 + 10;

int x,y,ans,a[MAXN];

bool check(int x){
    if (x % 4 == 0 && x % 100 != 0){
        return 1;
    }
    if (x % 400 == 0){
        return 1;
    }
    return 0;
}

int main(){
    cin >> x >> y;
    for (int i = x; i <= y; i++){
        if (check(i)){
            a[++ans] = i;
        }
    }
    cout << ans << '\n';
    for (int i = 1; i <= ans; i++){
        cout << a[i] << ' ';
    }
    return 0;
}