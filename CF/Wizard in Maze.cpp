#pragma target("avx")
#pragma optimize("O3")
#include<bits/stdc++.h>
using ll = int_fast64_t;
using P = std::pair<ll,ll>;
using PP = std::pair<P,ll>;
using V = std::vector<ll>;
 
#define REP(i,b,e) for(ll i=b; i<e; i++)
#define fi first
#define se second
 
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
 
int main(){
	int h, w;
	scanf("%d %d", &h, &w);
	int sx, sy, gx, gy;
	scanf("%d %d %d %d", &sx, &sy, &gx, &gy);
	sx--, sy--, gx--, gy--;
	
	char fie[h][w+1];
	REP(i, 0, h) scanf("%s", fie[i]);
	
	ll dist[h][w] = {};
	REP(i, 0, h) REP(j, 0, w) dist[i][j] = -1;
	bool used[h][w] = {};
	std::deque<PP> deq;
	deq.emplace_back(P(sx,sy), 0);
	while(!deq.empty()){
		PP pp = deq.front();
		deq.pop_front();
		P p = pp.fi;
		ll d = pp.se;
		if(used[p.fi][p.se]) continue;
		used[p.fi][p.se] = true;
		dist[p.fi][p.se] = d;
		
		REP(i, 0, 4){
			int nx = p.fi + dx[i], ny = p.se + dy[i];
			if(0<=nx && nx<h && 0<=ny && ny<w && fie[nx][ny]!='#'){
				deq.emplace_front(P(nx,ny), d);
			}
		}
 
		REP(i, -2, 3) REP(j, -2, 3) if(i!=0 || j!=0) {
			int nx = p.fi + i, ny = p.se + j;
			if(0<=nx && nx<h && 0<=ny && ny<w && fie[nx][ny]!='#'){
				deq.emplace_back(P(nx, ny), d+1);
			}
		}
	}
	printf("%ld\n", dist[gx][gy]);
	return 0;
}