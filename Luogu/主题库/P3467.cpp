#include"bits/stdc++.h"

using namespace std;

#define N 250010

int n,x,h[N],s[N],top,ans;

int main(){
	
	scanf("%d",&n);
	
	for(int i = 1; i <= n; ++i)
		scanf("%d%d",&x,&h[i]);
	for(int i = 1; i <= n; ++i){
		
		while(top > 0 && h[s[top]] > h[i]) top--;
		
		if(h[s[top]] != h[i]) ans++;
		
		s[++top] = i;
	}
	
	cout << ans;
	
	return 0;
}