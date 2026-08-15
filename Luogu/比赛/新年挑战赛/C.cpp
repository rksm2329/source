#include<bits/stdc++.h>

using namespace std;

char sp[100010][110],dsp[110][100010];

int sy[100010],kc[100010],sl[100010];

int main(){

    int n,k;

    cin >> n;

    for (int i = 1; i <= n; i++){

        cin >> sp[i] >> sy[i] >> kc[i];
    }

    int sum = 0;

    for (int i = 1; i <= k; i++){

        cin >> dsp[i] >> sl[i];

        for (int j = 1; j <= n; j++){

            if (strcmp(sp[j],dsp[i])){

                kc[j] -= sl[i];

                if (kc[j] < 0) {
                    
                    cout << '-' << i;

                    return 0;
                }

                sum += sy[j];

                break;
            }
        }
    }

    cout << sum;

    return 0;
}