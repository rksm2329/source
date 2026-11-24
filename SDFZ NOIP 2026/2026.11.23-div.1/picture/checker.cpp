#include "testlib.h"
#include <map>

const int MAXN = 1000;
namespace UFS{
	int fa[MAXN];
	void init(int n){
		for(int i=1; i<=n; ++i)
			fa[i] = i;
	}
	int find(int a){
		if(fa[a] == a) return a;
		return fa[a] = find(fa[a]);
	}
	bool merge(int a,int b){
		bool f = (find(a) != find(b));
		fa[find(a)] = find(b); return f;
	}
}

typedef std::pair<int,int> PII;
std::map<PII,int> mp;
inline PII make_p(int a,int b){
	return std::make_pair(a,b);
}

const int THRESHOLD_K = 900;
const int THRESHOLD_X = 10000000;
const int dir[][2] = {0,1,1,0,0,-1,-1,0};
int cnt[10]; // for every category
int main(int argc,char *argv[]){
	registerTestlibCmd(argc,argv);
	const int cnt_blk = inf.readInt();
	while(!ans.seekEof()) ans.readLine();
	const int k = ouf.readInt(1,THRESHOLD_K);
	for(int i=1,x,y; i<=k; ++i){
		x = ouf.readInt(1,THRESHOLD_X);
		y = ouf.readInt(1,THRESHOLD_X);
		mp[make_p(x,y)] = i;
	}

	int scc_cnt = k; UFS::init(k);
	std::map<PII,int>::iterator it;
	for(it=mp.begin(); it!=mp.end(); ++it){
		int x = (it->first).first;
		int y = (it->first).second;
		int cur_deg = 0;
		for(int d=0,tx,ty; d<4; ++d){
			tx = x+dir[d][0], ty = y+dir[d][1];
			if(mp.count(make_p(tx,ty))){
				++ cur_deg;
				const int &id = mp[make_p(tx,ty)];
				if(UFS::merge(it->second,id))
					-- scc_cnt;
			}
		}
		++ cnt[cur_deg];
	}

	if(cnt[1]) quitf(_wa,"Too Sharp The Picture!");
	if(cnt[3]) quitf(_wa,"Too Fat The Picture!");
	if(scc_cnt != 1) quitf(_wa,"Not Connected");
	if(cnt[4] != cnt_blk)
		quitf(_wa,"%d Exhausting \'#\' Instead Of Expected %d",cnt[4],cnt_blk);
	quitf(_ok,"Correct Answer :)");
	return 0;
}