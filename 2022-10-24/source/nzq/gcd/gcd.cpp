#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+10;
struct node{int u,v,w;}edge[200*maxn];
int gcd(int a,int b){return b==0?a:gcd(b,a%b);} 
int n,a[maxn],vis[maxn],dis[maxn],fa[maxn];
LL ans;
void sol1(){
	for(int i=1;i<=n;i++){
		int p=1;
		for(int j=1;j<=n;j++) if(!vis[j]&&dis[j]>dis[p]) p=j;
		vis[p]=1;
		ans+=dis[p];
		for(int j=1;j<=n;j++) if(!vis[j]) dis[j]=max(dis[j],gcd(a[p],a[j]));
	}
	cout<<ans<<endl;
	return ;
}
int find_set(int x){return fa[x]==x?x:fa[x]=find_set(fa[x]);}
bool cmp(node a,node b){return a.w>b.w;}
void sol2(){
	int cnt=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++){
		for(int j=max(1,i-100);j<=min(n,i+100);j++){
			if(i==j) continue;
			edge[++cnt]=node{i,j,gcd(a[i],a[j])};
		}
	}
	sort(edge+1,edge+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		int fx=find_set(edge[i].u),fy=find_set(edge[i].v);
		if(fx==fy) continue;
		fa[fy]=fx;
		ans+=edge[i].w;
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(n<=2000){sol1();return 0;}
	else sol2();
	return 0;
} 
