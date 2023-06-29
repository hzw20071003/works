#include<bits/stdc++.h> 
#define int long long
#define N 100000
using namespace std;
int n,a[100005],ans;
int fa[100005];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
signed main(){
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;++i){
		int x;scanf("%lld",&x);
		++a[x];
	}
	for(int i=1;i<=100000;++i)ans+=max(a[i]-1,1ll*0)*i,fa[i]=i;
	for(int i=N;i>=1;--i){
		int lst=0;
		for(int j=i;j<=N;j+=i){
			if(!a[j])continue;
			if(lst==0)lst=j;
			else{
				if(find(lst)!=find(j)){
					ans+=i;
					fa[find(lst)]=find(j);
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
