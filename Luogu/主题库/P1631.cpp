#include <bits/stdc++.h>

using namespace std;

#define LL int

const int maxn = 1e5 + 10;

LL a[maxn],b[maxn];

priority_queue<LL,vector<LL>,greater<LL> >p1;

int main(){
	
    int n;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
    
    for(int i = 1; i <= n; i++) scanf("%d",&b[i]);

    for(int i = 1; i <= sqrt(n); i++){
    	
        for(int j = i; j <= n / i; j++) p1.push(a[j] + b[i]);
        
        for(int j = i + 1; j <= n / i; j++) p1.push(a[i] + b[j]);
    }

    for(int i = 0; i < n; i++){
    	
        printf("%d ",p1.top());
        
        p1.pop();
    }
    
    return 0;
}

