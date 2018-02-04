#include <iostream>
#include <cmath>
using namespace std;
int a[10005];
int yin[1000001];
int main(){
	int n,p=0;
	cin >> n ;
	for(int i=0;i<n; i++){
		cin >> a[i];
		p = max(p,a[i]);
		int x= sqrt(a[i]+1);
		for(int j=1; j<=x; j++){
			if(a[i]%j == 0){
				yin[j]++;
				if(j*j!=a[i]){
					yin[a[i]/j]++;
				}
			}
		}
	}
	for(int i=1; i<=n; i++){
		while(yin[p]<i) p--;
		cout << p << endl;
	}
}
