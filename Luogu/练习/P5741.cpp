#include<iostream>
#include<algorithm>
#include<utility>
#include<string>

using namespace std;

const int MAXN = 1e3 + 10;

struct node{
    string name;
    int a,b,c,sum;
}a[MAXN];

struct spair{
    string ra,rb;
}ans[MAXN * MAXN];

int n;

bool cmp(const spair &i,const spair &j){
    if (i.ra != j.ra){
        return i.ra < j.ra;
    }
    return i.rb < j.rb;
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].name >> a[i].a >> a[i].b >> a[i].c;
        a[i].sum = a[i].a + a[i].b + a[i].c;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            if (abs(a[i].a - a[j].a) <= 5 && abs(a[i].b - a[j].b) <= 5 && abs(a[i].c - a[j].c) <= 5 && abs(a[i].sum - a[j].sum) <= 10){
                ans[++cnt] = {a[i].name,a[j].name};
            }
        }
    }
    sort(ans + 1,ans + cnt + 1,cmp);
    for (int i = 1; i <= cnt; i++){
        cout << ans[i].ra << ' ' << ans[i].rb << '\n';
    }
    return 0;
}