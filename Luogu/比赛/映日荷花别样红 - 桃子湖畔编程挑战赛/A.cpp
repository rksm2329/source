#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 10;

int c[MAXN][MAXN],b[MAXN][MAXN];

char s1[MAXN],s2[MAXN];

int len1,len2,t;

void jisuan(){
	
	for (int i = 1; i <= len1; i++){
		
		for (int j = 1; j <= len2; j++){
			
			if (s1[i - 1] == s2[j - 1]){
				
				c[i][j] = c[i - 1][j - 1] + 1;
				
				b[i][j] = 1;
			}
			else {
				
				if (c[i][j - 1] >= c[i - 1][j]){
					
					c[i][j] = c[i][j - 1];
					
					b[i][j] = 2;
				}
				else {
					
					c[i][j] = c[i - 1][j];
					
					b[i][j] = 3;
				}
			}
		}
	}
}

int main(){
	
	cin >> t;
	
	while (t--){
		
		cin >> s1;
	
		cin >> s2;
		
		len1 = strlen(s1);
		
		len2 = strlen(s2);
		
		for (int i = 0; i <= len1; i++){
			
			c[i][0] = 0;
		}
		for (int j = 0; j <= len2; j++){
			
			c[0][j] = 0;
		}
		
		jisuan();
		
		if (1.0 * c[len1][len2] / len1 * 100 >= 99){
			
			cout << "YES" << '\n';
		}
		else {
			
			cout << "NO" << '\n';
		}
	}
	
	return 0;
}