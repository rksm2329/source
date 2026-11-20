#include<iostream>
#include<queue>

using namespace std;

const int MAXV = 1e5 + 10;

int n,x,cnt[MAXV];
long long ans;

queue<long long> que1,que2;

inline long long read(){
    long long x = 0,f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-'){
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0',ch = getchar();
    }
    return x * f;
}

inline void write(long long x){
    if(x < 0){
        putchar('-'),x = -x;
    }
    if(x > 9){
        write(x / 10);
    }
    putchar(x % 10 + '0');
    return;
}

inline long long work(){
    long long x;
    if (que2.empty() || (!que1.empty() && que1.front() < que2.front())){
        x = que1.front();
        que1.pop();
    }
    else {
        x = que2.front();
        que2.pop();
    }
    return x;
}

int main(){
    n = read();
    ans = 0ll;
    for (int i = 1; i <= n; i++){
        x = read();
        cnt[x]++;
    }
    for (int i = 0; i < MAXV; i++){
        for (int j = 1; j <= cnt[i]; j++){
            que1.push(i);
        }
    }
    for (int i = 1; i < n; i++){
        long long a = work();
        long long b = work();
        ans += a + b;
        que2.push(a + b);
    }
    cout << ans;
    return 0;
}