#include <iostream>
#include <cstdio>
using namespace std;
int dp[25][30001];
int v[25],p[25];
int N,money;
int main(){
	cin >>  money>>N ;
	for(int i=0; i<N; i++){
		cin >> v[i] >> p[i];
	}
	for(int i=1;i<=money; i++){
		if(i>=v[0]){
			dp[0][i] = p[0]*v[0];
		}else{
			dp[0][i] = 0;
		}
	}
	for(int i=1; i<N; i++){
		for(int j=1; j<=money; j++){
			if(j>=v[i]){
				dp[i][j] = max(dp[i-1][j-v[i]]+p[i]*v[i],dp[i-1][j]);
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	cout << dp[N-1][money] << endl;
}
