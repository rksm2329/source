#include<bits/stdc++.h>

using namespace std;

const int N = 1000005;

int n,k;

struct node{int v,id;}a[N];

deque<node> qmin,qmax;

int main(){
	
    cin >> n >> k;
    
    for(int i = 1; i <= n; i++)cin >> a[i].v,a[i].id = i;
    
    for(int i = 1; i <= n; i++){
    	   
        while(!qmax.empty() && qmax.back().v <= a[i].v)qmax.pop_back();    
        
        qmax.push_back(a[i]);
        
        if(qmax.front().id == i-k)qmax.pop_front();
        
        if(i >= k)cout << qmax.front().v << endl;
    }
    
    return 0;
}