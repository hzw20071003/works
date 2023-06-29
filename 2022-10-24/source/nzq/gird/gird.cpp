#include<bits/stdc++.h>
#define mp make_pair 
using namespace std;
typedef pair<int,int> pii;
const int maxn=1010,N=1e5+10,inf=1e9;
int n,m,q,l,A[maxn][maxn],B[maxn][maxn];
int vis[maxn][maxn],dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int T[N<<2],xhj[N<<2];
void push_down(int pos){
	T[pos]+=xhj[pos];
	xhj[pos<<1|1]+=xhj[pos];
	xhj[pos<<1]+=xhj[pos];
	xhj[pos]=0;
}
void update(int pos,int L,int R,int l,int r,int w){
	if(R<l||L>r) return ;
	if(l<=L&&r>=R){
		xhj[pos]+=w;
		push_down(pos);
		return ;
	}
	int mid=(L+R)>>1;
	update(pos<<1,L,mid,l,r,w);
	update(pos<<1|1,mid+1,R,l,r,w);
	T[pos]=max(T[pos<<1],T[pos<<1|1]);
}
int query(int pos,int L,int R,int l,int r){
	if(R<l||L>r) return -inf;
	if(l<=L&&r>=R){
		push_down(pos);
		return T[pos];
	}
	int mid=(L+R)>>1;
	return max(query(pos<<1,L,mid,l,r),query(pos<<1|1,mid+1,R,l,r));
}
bool bfs(int sx,int sy,int ex,int ey){
	memset(vis,0,sizeof(vis));
	queue<pii> q;
	q.push(mp(sx,sy));
	vis[sx][sy]=1;
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;
		q.pop();
		if(x==ex&&y==ey) return 1;
		for(int i=0;i<3;i++){
			int tx=x+dir[i][0];
			int ty=y+dir[i][1];
			if(tx<=0||ty<=0||tx>n||ty>m||vis[tx][ty]||A[tx][ty]>=l) continue;
			vis[tx][ty]=1;
			q.push(mp(tx,ty));
		}
	} 
	return 0;
}
void sol(){
	while(q--){
		int o,a,b,c,d,w;
		cin>>o>>a>>b>>c>>d;
		if(o==1){
			cin>>w;
			update(1,1,m,b,d,w);
		}else{
			cout<<(query(1,1,m,b,d)<l?"yes":"no")<<endl;
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("gird.in","r",stdin);
	freopen("gird.out","w",stdout);
	cin>>n>>m>>l>>q;
	if(n==1){
		sol();
		return 0;
	}
	while(q--){
		int o,a,b,c,d,w;
		cin>>o>>a>>b>>c>>d;
		if(o==1){
			cin>>w;
			B[a][b]+=w;
			B[c+1][d+1]+=w;
			B[a][d+1]-=w;
			B[c+1][b]-=w;
		}else{
			for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) B[i][j]=B[i][j]+B[i-1][j]+B[i][j-1]-B[i-1][j-1];
			for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) A[i][j]+=B[i][j];
			memset(B,0,sizeof(B));
			cout<<(bfs(a,b,c,d)?"yes":"no")<<endl;
		}
	}
	return 0;
} 
/*
1 6 3 4
1 1 2 1 3 1 
2 1 1 1 6
1 1 2 1 6 2
2 1 1 1 6
*/
