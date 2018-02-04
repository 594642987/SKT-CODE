#include <iostream>
using namespace std;
const int modn = 100000000;
int main(){
	long n,m;
	cin >> n >>m ;
	long max_n = n>m?n:m;
	long min_n = n<m?n:m;
	long temp;
	while(min_n>0){
		temp = max_n%min_n;
		max_n = min_n;
		min_n = temp;
	}
	if(max_n == 1){
		cout << 1;
		return 0;
	}
	if(max_n == 2){
		cout << 1;
		return 0;
	}
	long long f[3];
	f[1] = 1;
	f[2] = 1;
	for(long i=2; i<max_n; i++){
		f[0] = f[1];
		f[1] = f[2];
		f[2] = (f[0]+ f[1])%modn;	
	}
	cout << f[2];
}
