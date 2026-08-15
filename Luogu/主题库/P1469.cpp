#include<bits/stdc++.h>

using namespace std;

int a[10000010],cnt[100000010];

int main(){
	
	int n;
	
	cin >> n;
	
	for (int i = 1; i <= n; i++){
		
		cin >> a[i];
		
		cnt[a[i]]++;
	}
	
	for (int i = 1; i <= 100000000; i++){
		
		if (cnt[i] % 2 == 1){
			
			cout << i;
			
			return 0;
		}
	}
	
	return 0;
}