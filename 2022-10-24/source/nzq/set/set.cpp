#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,maxn=1e6+10;
int n,ans,cnt,num[30],box[30],p[maxn];
int main(){
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	cin>>n;
	for(int i=1;i<(1<<(n+1));i++){
		int tmp=i,j;
		cnt=0;
		memset(box,0,sizeof(box));
		for(j=0;tmp!=0;j++,tmp>>=1)if(tmp&1){
			num[++cnt]=j;
			box[j]=1;
		}
		j--;
		int f=0;
		for(int j=1;j<=cnt;j++){
			if(f) break;
			for(int k=1;k<=cnt;k++){
				box[num[j] xor num[k]]=1;
			}
		}
		int sum=0;
		for(int i=0;i<=n;i++) sum=(sum<<1)+box[i];
		if(!p[sum]) ans++,p[sum]=1;
	}
	cout<<ans<<endl;
	return 0;
} 
