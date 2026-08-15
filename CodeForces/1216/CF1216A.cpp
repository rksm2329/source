#include<bits/stdc++.h>

using namespace std;

int n,ans;

string s;

int main(){
	
	cin >> n >> s;
	
	int len = s.size();
	
	for (int i = 0; i < len; i += 2){
		
		if (s[i] == s[i + 1]){
			
			s[i] = (s[i] == 'a') ? 'b' : 'a';
			
			ans++;
		}
	}
	
	cout << ans << '\n' << s;
	
	return 0;
}