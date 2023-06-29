#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,cnt,maxn,tim,ans;
int a[N],vis[N],fa[N],num[N];
bool zs[N];
struct node{
	int u,v,w;
};
vector<node> e;
bool cmp(node x,node y){
	return x.w>y.w;
}
bool pd(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}
int gcd(int x,int y){
	if(y==0){
		return x;
	}else{
		return gcd(y,x%y);
	}
}
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		fa[i]=i;
		maxn=max(maxn,a[i]);
		vis[a[i]]=i;
		if(pd(a[i])){
			zs[i]=true;
		}
	}
	if(n<=400){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int g=gcd(a[i],a[j]);
//				cout<<i<<" "<<j<" "<<g<<endl;
				e.push_back((node){i,j,g});
				e.push_back((node){j,i,g});
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			bool flag=false;
			int x=a[i];
			while(x<=maxn){
				if(vis[x]!=0 && (num[x]>1 || x!=a[i])){
					flag=true;
					e.push_back((node){i,vis[x],a[i]});
					e.push_back((node){vis[x],i,a[i]});
				}
				x+=a[i];
			}
			if(flag){
				continue;
			}
			if(zs[a[i]]){
				if(i!=1){
					e.push_back((node){i,1,1});
					e.push_back((node){1,i,1});
				}else{
					e.push_back((node){i,2,1});
					e.push_back((node){2,i,1});
				}
				continue;
			}
			for(int j=i+1;j<=n;j++){
				int g=gcd(a[i],a[j]);
				e.push_back((node){i,j,g});
				e.push_back((node){j,i,g});
			}
		}
	}
	sort(e.begin(),e.end(),cmp);
	for(int i=0;i<e.size() && tim<n-1;i++){
		int x=e[i].u,y=e[i].v,w=e[i].w;
		int fx=find(x),fy=find(y);
		if(fx!=fy){
			ans+=w;
			tim++;
			fa[fx]=fy;
		}
	}
	cout<<ans;



	return 0;
}
/*
5 
5 6 7 10 21
*/
