#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 1e6 + 10;

struct node{
    int x,y;
}a[MAXN];

int n;

bool cmp(const node &i, const node &j){
    return i.y < j.y;
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].y;
    }
    sort(a + 1,a + n + 1,cmp);
    int p = 0,ans = 0;
    for (int i = 1; i <= n; i++){
        if (p <= a[i].x){
            p = a[i].y;
            ans++;
        }
    }
    cout << ans;
    return 0;
}