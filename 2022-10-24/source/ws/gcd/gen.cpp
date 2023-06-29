#include<bits/stdc++.h>
using namespace std;
int main(){
	srand(time(0));
	freopen("gcd.in","w",stdout);
	int n=100000,maxv=100000;
	cout<<n<<endl;
	for(int i=1;i<=n;i++)
		cout<<(rand()*32768LL+rand())%maxv+1<<' ';
	return 0;
}
