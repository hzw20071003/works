#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int n,ans;
bool f[25];
void dfs(int now){
	if(now==n+1){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(f[i]&&f[j]&&f[i^j]!=1)return;
			}
		}
		++ans;
		return;
	}
	dfs(now+1);
	f[now]=1;
	dfs(now+1);
	f[now]=0;
}
signed main(){
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout); 
	scanf("%lld",&n);
	f[0]=1;
	if(n<=20)dfs(1);
	else{
		ans=1;
		int lst=1;
		for(int i=1;i<=n;i*=2){
			ans=(ans+lst*(n-i+1)/i/(i*2-1)%mod)%mod;
			lst=lst*(n-i+1)/i/(i*2-1)%mod;
		}
	}
	printf("%lld",ans);
	return 0; 
}
