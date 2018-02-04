#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
struct cmp{
	bool operator()(int x, int y){
		return x>y;
	}
};
priority_queue<int,vector<int>,cmp> da;
priority_queue<int> xiao;
int a[200005];
int M,N;
int main(){
	cin >> M >> N;
	for(int i=1; i<=M; i++){
		scanf("%d",&a[i]);
	}
	int n,j=1;
	for(int i=1; i<=N; i++){
		cin >>n;
		for(j;j<=n; j++){
			if(!xiao.empty()&&a[j]<xiao.top()){
				xiao.push(a[j]);
				da.push(xiao.top());
				xiao.pop(); 
			}else{
				da.push(a[j]); 
			}
		}
		xiao.push(da.top());
		da.pop();
		cout << xiao.top() <<endl;
	}
	return 0;
}
