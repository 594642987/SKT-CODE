#include <iostream>
#include <cstdio>
using namespace std;
const int N = 200000*2+5;
int pre[N],k1[N];
int x1[N],y1[N],x3[N],y3[N],sum[N];
bool sign[N];
int n,m,k,cnt,ans,a; 
int find(int x){
	if(pre[x]!=x){
		pre[x] = find(pre[x]);
	}
	return pre[x];
}
int main(){
	scanf("%d%d",&n,&m);
	ans = n;
	for(int i=0; i<n; i++){
		pre[i] = i; sign[i] = true;
	}
	
	for(int i=0; i<m; i++){
		scanf("%d%d",&x1[i],&y1[i]);
	}
	
	scanf("%d",&k);
	ans -=k;
	for(int i=1; i<=k; i++){
		scanf("%d",&a);
		k1[i] = a;
		sign[a] = false;
	}
	
	for(int i=0; i<m; i++){
		if(sign[x1[i]]&&sign[y1[i]]){
			int x2 = find(x1[i]);
			int y2 = find(y1[i]);
			if(x2!=y2){
				pre[x2] = y2;
				ans--;
			}
		}else{
			x3[cnt] = x1[i];
			y3[cnt++] = y1[i];
		}
	}
	for(int i=k; i>=0; i--){
		sum[i] = ans;
		if(i == 0) break;
		sign[k1[i]] = true;
		ans++;
		for(int j=0; j<cnt; j++){
			if(sign[x3[j]]&&sign[y3[j]]){
				int x2 = find(x3[j]);
				int y2 = find(y3[j]);
				if(x2!=y2){
					pre[x2] = y2;
					ans--;
				}
			}
		}
	}
	for(int i=0; i<=k; i++){
		printf("%d\n",sum[i]);
	}
	return 0;
}
