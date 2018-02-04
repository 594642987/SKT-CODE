#include <iostream>
using namespace std;
const int modn = 10007;
int  a,b,k,n,m;
int xi[1001][1001];
long long pown(int a,int n){
	long long ans = 1;
	for(int i=0; i<n; i++){
		ans = (ans*a)%modn;
	}
	return ans;
}
int main(){
	cin >> a >> b >> k >> n >> m;
	xi[0][0] = 0; xi[0][1] = 1;
	xi[1][0] = 0; xi[1][1] = 1; xi[1][2] = 1;
	for(int i=2;i<=k; i++){
		for(int j=1; j<=i+1; j++){
			xi[i][j] = (xi[i-1][j-1] + xi[i-1][j])%modn;
		}
	}
	long long temp = xi[k][k+1-n];
	temp = temp*pown(a,n)*pown(b,m)%modn;
	cout << temp;
	return 0;
}
