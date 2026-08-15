#include<iostream>

using namespace std;

int t[601],n,w,x,s;

int main(){
    cin >> n >> w;
    for (int i = 1; i <= n; i++){
        cin >> x;
        t[x]++;
        s = 0;
        for (int j = 600; j >= 0; j--){
            s += t[j];
            if (s >= max(1,i * w / 100)){
                cout << j << ' ';
                break;
            }
        }
    }
    return 0;
}