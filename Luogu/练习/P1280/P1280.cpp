#include <bits/stdc++.h>
  
using namespace std;

long int n, k, sum[10001], num = 1, f[10001];

struct ren {
  long int ks,js; 
};

ren z[10001];  

int cmp(ren a, ren b) {  
  return a.ks > b.ks; 
} 

int main(){
	
    long int i,j; 
      
    cin >> n >> k; 
     
    for(i = 1; i <= k; i++){
	    
	    cin >> z[i].ks >> z[i].js;
	        
	    sum[z[i].ks]++;  
    }  
    
    sort(z + 1,z + k + 1,cmp);  
    
    for(i = n; i >= 1; i--){  
     
        if(sum[i] == 0) 
        
        	f[i]=f[i+1]+1;  
        else for(j = 1; j <= sum[i]; j++){
        	
            if(f[i + z[num].js] > f[i])
            
	            f[i] = f[i + z[num].js]; 
	             
	            num++;
        }  
    } 
    
    cout << f[1] << endl;  
    
    return 0;
}