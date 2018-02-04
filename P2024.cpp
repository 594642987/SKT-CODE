#include <iostream>
#include <cstdio>
using namespace std;
const int N = 50005;
int n,k,count;
int pre[N*3];
int find(int x){
	if(x == pre[x]) return x;
	else return pre[x] = find(pre[x]);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n*3; i++){
		pre[i] = i;
	}
	int a,b,c;
	for(int i=0; i<k; i++){
		scanf("%d%d%d",&a,&b,&c);
		if(b>n||c>n){
			count++;
			continue;
		}
		int b1 = find(b),b2 = find(b+n), b3 = find(b+2*n);
		int c1 = find(c),c2= find(c+n), c3 = find(c+2*n);
		if(a == 1){
			if(b1 == c2 || b2 == c1 || b1 == c3 || b3 == c1|| b2 == c3|| c2 == b3) count++;
			else{
				pre[b1] = c1; 
				pre[b2] = c2;
				pre[b3] = c3;
			}
		}else{
			if(b1 == c1|| b2 == c2 || b3 == c3 || b1 == c2|| b2 == c3 || b3 == c1) count++;
			else{
				pre[b2] = c1;
				pre[b1] = c3;
				pre[b3] = c2; 
			} 
		}
	}
	
	cout << count << endl;
	return 0;
}
