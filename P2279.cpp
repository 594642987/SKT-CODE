#include <bits/stdc++.h>
using namespace std;

const int N = 1002;
int tot = 0, ans = 0;
int fa[N],nxt[N*2],first[N];
struct edge{
	int from,to;
}ed[N*2];

void build(int ff,int tt){
	ed[++tot] = (edge){ff,tt};
	 nxt[tot] = first[ff];
	 first[ff] = tot;
}
void dfs(int n,int p = -1){
	int maxn = -N, minn = N;
	for(int i=first[n];i!=-1;i = nxt[i]){
		 int v = ed[i].to;
        if(v != p)
        {
            dfs(v, n);
            maxn = max(fa[v], maxn);
            minn = min(fa[v], minn);
        }
    }
    if(maxn + minn <= 3)
        fa[n] = minn + 1;
    else fa[n] = maxn + 1;
    if(minn == N)
        fa[n] = 3;
    if(fa[n] == 5)
    {
        ans ++;
        fa[n] = 0;
    }
    else if(p == -1 && fa[n] >= 3)
        ans ++;
	
}
int main(){
	int n,v;
	cin >> n;
	memset(first,-1,sizeof(first));
	for(int i=1; i<n; i++){
		scanf("%d",&v);
		v--;
		build(v,i);
		build(i,v);
	}
	dfs(0);
	cout << ans << endl;
	return 0;
}
