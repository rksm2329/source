#include<bits/stdc++.h>

using namespace std;

char x,z;

long long y,w;

int main(){
	
	cin >> x >> y >> z >> w;
	
	if (x >= 'a' && x <= 'z' && z >= 'a' && z <= 'z' && x == z){
		
		cout << "valid\n";
	}
	else {
		
		cout << "Invalid\n-1";
		
		return 0;
	}
	
	long long ans = 0;
	
	if (y <= w){
		
		ans = w - y + 1;
	}
	else {
		
		ans = y - w + 1;
	}
	
	printf("%lld",ans);
	
	return 0;
}