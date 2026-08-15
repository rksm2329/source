#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

int n,tot,a[MAXN],b[MAXN],cnt[MAXN];

int main(){
	
	cin >> n;
	
	for (int i = 1; i <= n; i++){
		
		cin >> a[i];
		
		cnt[a[i]]++;
		
		if (cnt[a[i]] == 1){
			
			b[++tot] = a[i];
		}
	}
	
	cout << tot;
	
	return 0;
}