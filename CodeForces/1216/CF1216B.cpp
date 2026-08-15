#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 10;

int n,ans,a[MAXN],cnt[MAXN];

int main(){
	
	cin >> n;
	
	for (int i = 1; i <= n; i++){
		
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; i++){
		
		cnt[i] = i;
	}
	
	for (int i = 1; i <= n; i++){
		
		for (int j = 1; j <= n; j++){
			
			if (a[i] > a[j]){
				
				swap(a[i],a[j]);
				
				swap(cnt[i],cnt[j]);
			}
		}
	}
	
	for (int i = 1; i <= n; i++){
		
		ans += a[i] * (i - 1) + 1;
	}
	
	cout << ans << '\n';
	
	for (int i = 1; i <= n; i++){
		
		cout << cnt[i] << ' ';
	}
	
	return 0;
}