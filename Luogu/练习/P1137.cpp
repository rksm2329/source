#include<iostream>
#include<queue>

using namespace std;

const int MAXN = 1e5 + 5;

int n,m,u,v,in[MAXN],f[MAXN],head[MAXN],tot;

struct edge{
	
	int to,next;
}G[MAXN << 1];

void addedge(int u,int v){
	
	G[++tot].next = head[u];
	
	head[u] = tot;
	
	G[tot].to = v;
}

void topo(){
	
	queue<int> q;
	
	for (int i = 1; i <= n; i++){
		
		if (!in[i]){
			
			f[i] = 1;
			
			q.push(i);
		}
	}
	
	while (!q.empty()){
		
		int u = q.front();
		
		for (int i = head[u]; i; i = G[i].next){
			
			int v = G[i].to;
			
			f[v] = max(f[v],f[u] + 1);
			
			in[v]--;
			
			if (!in[v]){
				
				q.push(v);
			}
		}
		
		q.pop();
	}
}

int main(){
	
	cin >> n >> m;
	
	for (int i = 1; i <= m; i++){
		
		cin >> u >> v;
		
		addedge(u,v);
		
		in[v]++;
	}
	
	topo();
	
	for (int i = 1; i <= n; i++){
		
		cout << f[i] << endl;
	}
	
	return 0;
}