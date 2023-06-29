#include<bits/stdc++.h> 
#define int long long
using namespace std;
int n,m,l,q;
struct T{
	int val,tag;
}tree[400005];
void pushdown(int x){
	tree[x*2].tag+=tree[x].tag;
	tree[x*2+1].tag+=tree[x].tag;
	tree[x].tag=0;
}
void upd(int x,int nl,int nr,int l,int r,int v){
	if(nl>r||nr<l)return;
	if(nl>=l&&nr<=r){
		tree[x].tag+=v;
		return;
	}
	pushdown(x);int mid=nl+nr>>1;
	upd(x*2,nl,mid,l,r,v);upd(x*2+1,mid+1,nr,l,r,v);
	tree[x].val=max(tree[x].val,max(tree[x*2].val+tree[x*2].tag,tree[x*2+1].val+tree[x*2+1].tag));
	return;
}
int query(int x,int l,int r,int tl,int tr){
	if(l>tr||r<tl)return 0;
	if(l>=tl&&r<=tr)return tree[x].val+tree[x].tag;
	int mid=l+r>>1;
	return max(query(x*2,l,mid,tl,tr),query(x*2+1,mid+1,r,tl,tr));
}
int sum[1005][1005],dx[4]={1,0},dy[4]={0,1};
bool vis[1005][1005];
bool dfs(int x,int y,int tx,int ty){
	if(x==tx&&y==ty)return 1;
	for(int i=0;i<2;++i){
		int nx=x+dx[i],ny=y+dy[i];
		if(!vis[nx][ny]&&nx>0&&ny>0&&nx<=n&&ny<=m&&sum[nx][ny]<l){
			vis[nx][ny]=1;
			bool f=dfs(nx,ny,tx,ty);
			if(f)return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("grid.in","r",stdin);
	freopen("grid.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&l,&q);
	if(n==1){
		while(q--){
			int op,a,b,c,d,e;
			scanf("%lld%lld%lld%lld%lld",&op,&a,&b,&c,&d);
			if(op==1){
				scanf("%lld",&e);
				upd(1,1,m,b,d,e);
			}
			else{
				int x=query(1,1,m,b,d);
				if(x>=l)printf("no\n");
				else printf("yes\n");
			}
		}
	}
	else{
		while(q--){
			int op,a,b,c,d,e;
			scanf("%lld%lld%lld%lld%lld",&op,&a,&b,&c,&d);
			if(op==1){
				scanf("%lld",&e);
				for(int i=a;i<=c;++i)
					for(int j=b;j<=d;++j)
						sum[i][j]+=e;
			}
			else{
				memset(vis,0,sizeof(vis));
				bool x=dfs(a,b,c,d);
				if(!x||sum[a][b]>=l)printf("no\n");
				else printf("yes\n");
			}
		}
	}
	return 0;
}
