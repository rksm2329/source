#include<bits/stdc++.h>

using namespace std;

int a[100010],b[100010];

int main(){

    int n,m;

    scanf("%d%d",&n,&m);

    for (int i = 1; i <= n; i++){

        scanf("%d",&a[i]);
    }

    for (int i = 1; i <= m; i++){

        scanf("%d",&b[i]);
    }

    int cnt = 0;

    for (int i = 1; i <= m; i++){

        int min = 10000000;

        for (int j = 1; j <= n; j++){

            if (abs(b[i] - a[j]) < min){

                min = abs(b[i] - a[j]);
            }
        }

        cnt += min;
    }

    printf("%d",cnt);
    
    return 0;
}