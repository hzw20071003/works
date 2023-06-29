#include<bits/stdc++.h>
using namespace std;
const int N=10000010,mod=1e9+7;
int n,cnt,ans;
int a[N];
bool vis[N];
void dfs(int x){
	if(x==n+1){
		bool flag=true;
		for(int i=1;i<=cnt;i++){
			for(int j=i+1;j<=cnt;j++){
				int x=a[i]^a[j];
				if(x>n || !vis[x]){
					flag=false;
					break;
				}
			}
			if(!flag){
				break;
			}
		}
		if(flag){
			ans=(ans+1)%mod;
		}
		return;
	}
	a[cnt+1]=0;
	vis[x]=false;
	dfs(x+1);
	a[++cnt]=x;
	vis[x]=true;
	dfs(x+1);
	a[cnt]=0;
	cnt--;
	vis[x]=false;
	return;
}
int main(){
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	cin>>n;
	dfs(1);
	cout<<ans;



	return 0;
}

