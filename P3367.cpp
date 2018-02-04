#include <iostream>
#include <cstdio>
using namespace std;

int fa[10001];
int N,M;
int get_fa(int x){
	return x == fa[x]?x:fa[x] = get_fa(fa[x]);
}
int main(){
	cin >> N >> M;
	for(int i=1; i<N; i++){
		fa[i] = i;
	}
	
	int z,x,y;
	for(int i=0; i<M; i++){
		scanf("%d%d%d",&z,&x,&y);
		if(z == 1){
			fa[get_fa(x)] = get_fa(y);
		}else if(z == 2){
			if(get_fa(x) == get_fa(y)){
				cout << "Y" << endl;
			}else{
				cout << "N" << endl;
			}
		}
	}
}
