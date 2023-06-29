#include<bits/stdc++.h>
using namespace std;
int main(){
	int ans=0;
	for(int i=1;i<=100000;i++){
		int sum=1;
		for(int j=1;j<=i/2;j++)if(i%j==0)sum++;
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
