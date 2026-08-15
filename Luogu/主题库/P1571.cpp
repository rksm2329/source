#include<bits/stdc++.h>

using namespace std;

int n,m;

map<int,bool> v;

int a[101000],b[101000];

int main(){
	
	scanf("%d%d",&n,&m);
	
	for (int i = 1; i <= n; i++) {scanf("%d",&a[i]);}
	
	for (int i = 1; i <= m; i++) {scanf("%d",&b[i]);v[b[i]] = true;}
	
	for (int i = 1; i <= n; i++) if(v[a[i]]) cout << a[i] << " ";
	
	return 0;
}