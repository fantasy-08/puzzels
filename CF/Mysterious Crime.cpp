#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int N = 1e5 + 7;

int n, m;
int mn[N];
int ren[N];
int perm[15][N];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= n; ++j)
			scanf("%d", &perm[i][j]);
	
	for(int i = 1; i <= n; ++i)
		ren[perm[1][i]] = i;
	
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= n; ++j)
			perm[i][j] = ren[perm[i][j]];
		
	for(int i = 1; i <= n; ++i)
		mn[i] = n;
		
	for(int i = 1; i <= m; ++i){
		int cur = 1;
		for(int j = 1; j <= n; ++j){
			if(cur < j)
				++cur;

			while(cur < n && perm[i][cur + 1] == perm[i][cur] + 1)
				++cur;
			mn[perm[i][j]] = min(mn[perm[i][j]], perm[i][cur]);
		}
	}
	
	LL res = 0;
	int now = 1;
	while(now <= n){
		int cur = mn[now] - now + 1;
		res += 1LL * (cur + 1) * cur / 2LL;
		now = mn[now] + 1;
	}
	
	printf("%lld\n", res);
	return 0;
}
// Problem : D. Mysterious Crime
// Contest : Codeforces - Codeforces Round #519 by Botan Investments
// URL : https://codeforces.com/problemset/problem/1043/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

