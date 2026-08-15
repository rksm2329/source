#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define res register int

const int MAXN=100000+10;

ll n,k,total,s[MAXN];

map<ll,bool> mmp;

int main(){
	
	cin >> n >> k;
	
	for(res i = 1; i <= n; ++i) cin >> s[i];
	
	sort(s + 1,s + n + 1);
	
	for(res i = 1; i <= n; ++i){
		
		if(!mmp[s[i]] && (s[i]%k || !mmp[s[i] / k])) mmp[s[i]] = 1,++total;
	}
	
	cout << total;
	
	return 0;
}
