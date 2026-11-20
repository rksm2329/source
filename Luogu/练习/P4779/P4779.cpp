#include<bits/stdc++.h>

using namespace std;

int n,m,t,cnt,head[1000100],dis[1000100];

bool vis[1000100];

struct edge{
	
	int u,v,w,next;
} s[1000100];

void add(int u,int v,int w){
	
	cnt++;
	
	s[cnt].u = u;
	
	s[cnt].v = v;
	
	s[cnt].w = w;
	
	s[cnt].next = head[u];
	
	head[u] = cnt;
}

void dijkstra(){
	
	for (int i = 1; i <= n; i++) dis[i] = 2147483647;
	
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	
	dis[t] = 0;
	
	q.push(make_pair(0,t));
	
	while(!q.empty()){
		
		int tmp = q.top().second;
		
		q.pop();
		
		if (vis[tmp]) continue;
		
		vis[tmp] = 1;
		
		for(int i = head[tmp]; i; i = s[i].next){
			
			int v = s[i].v,dist = s[i].w;
			
			if(dis[v] > dis[tmp] + dist){
				
				dis[v] = dis[tmp] + dist;
				
				q.push(make_pair(dis[v],v));
			}
		}
	}
}

int main(){
	
	cin >> n >> m >> t;
	
	for (int i = 1; i <= m; i++){
		
        int u,v,w;
        
		cin >> u >> v >> w;
		
		add(u,v,w);
	}
	
	dijkstra();
	
	for (int i = 1; i <= n; i++) cout << dis[i] << ' ';
	
	return 0;
}
