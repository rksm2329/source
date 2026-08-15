#include<iostream>

using namespace std;

int main(){

    int n,y;

    cin >> n >> y;
    
    if (n / y < y){
    	
    	cout << n + n / y;
    	
    	return 0;
    }
    
    int sum = 0;
    
    while (n >= y){
    	
    	sum += n;
    	
    	// cout << sum << endl;
    	
    	n = n / y + n % y;
    }
    
    cout << sum;
    
    return 0;
}