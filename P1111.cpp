#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct road{
	int x,y,time;
}r[100001];
int vil[1001],num[1001];
int N,M;
bool cmp(const road r1, const road r2){
	return r1.time < r2.time;
}
int get_fa(int x){
	if(vil[x] == x) return x;
	return vil[x] = get_fa(vil[x]);
}
int main(){
	cin >> N >> M;
	for(int i=1; i<=N; i++){
		vil[i] = i;
		num[i] = 1;
	}
	for(int i=1; i<=M; i++){
		scanf("%d%d%d",&r[i].x,&r[i].y,&r[i].time);
	}
	sort(r+1,r+M+1,cmp);
	
	int a,b;
	for(int i=1; i<=M; i++){
		a = get_fa(r[i].x);
		b = get_fa(r[i].y);
		if(a!=b){
			vil[b] = a;
			num [a] +=num[b];
		}
		if(num[a] == N){
			cout << r[i].time << endl;
			return 0;
		}
	}
	if(num[get_fa(1)]!=N){
		cout << -1;
	}
}
