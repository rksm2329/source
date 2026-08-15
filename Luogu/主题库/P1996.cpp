#include<bits/stdc++.h>

using namespace std;

int a[10010];

int main(){

    int n,m;

    cin >> n >> m;

    int head = 1,tail = 1;

    for (int i = 1; i <= n; i++){

        a[i] = tail,tail++;
    }

    while (head < tail){

        for (int i = 1; i < m; i++){

            a[tail] = a[head],tail++,head++;
        }

        cout << a[head] << ' ';

        head++;
    }

    return 0;
}