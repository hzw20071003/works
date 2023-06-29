#include<bits/stdc++.h>
using namespace std;

struct edges{
	int u,v,w;
}edge[1000005];
bool cmp(edges x,edges y){return x.w>y.w;}

int f[1005];
void init_f(int n){for(int i=1;i<=n;i++)f[i]=i;}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}

int n,a[1005],cnt;
int main(){
	freopen("gcd.in","r",stdin);
	freopen("dp.out","w",stdout);
	cin>>n;init_f(n);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
		edge[++cnt]=(edges){i,j,__gcd(a[i],a[j])};
	
	sort(edge+1,edge+cnt+1,cmp);
	long long ans=0;
	for(int i=1,sum=0;i<=cnt;i++){
		if(find(edge[i].u)!=find(edge[i].v)){
//			cerr<<edge[i].u<<' '<<edge[i].v<<endl;
			f[find(edge[i].u)]=find(edge[i].v);
			ans+=edge[i].w;
			sum++;
			if(sum==n-1)break;
		}
	}
	cout<<ans;
	return 0;
}
