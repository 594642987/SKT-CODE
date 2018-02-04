#include <iostream>
#include <algorithm>
using namespace std;
int N,M;
int meat[101];
int f[101][1001];
int main(){
	cin >> N >> M;
	for(int i=1; i<=N; i++){
		cin >> meat[i];
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M;j++){
			if(j == meat[i]) f[i][j] = f[i-1][j]+1;
			if(j>meat[i]) f[i][j] = f[i-1][j] + f[i-1][j-meat[i]];
			if(j<meat[i]) f[i][j] = f[i-1][j];
		}
	}
	cout << f[N][M] << endl;
	return 0;
}
