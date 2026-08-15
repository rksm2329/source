#include<bits/stdc++.h>

using namespace std;

int stu[110],u[10010],v[10010];

int main(){

    int k,n,m;

    cin >> k >> n >> m;

    for (int i = 1; i <= k; i++){

        cin >> stu[i];
    }

    for (int i = 1; i <= m; i++){

        cin >> u[i] >> v[i];
    }

    for (int i = 1; i <= 1000; i++){

        int cnt = 0;

        if (v[i] == i){

            int flag = 0;

            for (int j = 1; j <= k; j++){

                if (u[i] == stu[j]){

                    flag = 1;

                    break;
                }
            }
        }
    }

    return 0;
}