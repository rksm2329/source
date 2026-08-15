#include<bits/stdc++.h>

using namespace std;

#define il inline

#define qwq s.begin(),s.end(),x

#define upp upper_bound

#define low lower_bound

int sum,n,x;

vector<int>s;

vector<int>::iterator it;

int main(){
	
	cin >> n;
	
	s.insert(it,-INT_MAX);
	
	for(int i = 1; i <= n; ++i){
		
		cin >> x;
		
		if(i == 1) sum += x;
		
		else{
			
			int a = *--low(qwq),b = *low(qwq);
			
			if(a == -INT_MAX) sum += abs(b - x);
			
			else sum += min(abs(a - x),abs(b - x));
			
		}
		
		s.insert(upp(qwq),x);
	}
	
	cout << sum;
		
	return 0;
}
