#include<bits/stdc++.h>

using namespace std;

char s[255];

int main(){
	
	cin >> s;
	
	int len = strlen(s);
	
	int a = 0,b = 0;
	
	for (int i = 0; i < len; i++){
		
		if (s[i] == 'b' || s[i + 1] == 'o' || s[i + 2] == 'y'){
			
			a++;
		}
		
		if (s[i] == 'g' || s[i + 1] == 'i' || s[i + 2] == 'r' || s[i + 3] == 'l'){
			
			b++;
		}
	}
	
	cout << a << endl << b;
	
	return 0;
}