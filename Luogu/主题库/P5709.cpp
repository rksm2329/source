#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	double d = 1.0 * y / x;
	int e = (int)ceil(d);
	int res = n - e;
	res < 0 ? printf("0") : printf("%d",res);
	return 0;
}