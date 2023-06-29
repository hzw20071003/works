#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,m,l;
map<int,int> p[N],dif[N],dp[N];
map<int,bool> vis[N];
int main(){
	freopen("grid.in","r",stdin);
	freopen("grid.out","w",stdout);
	int T;
	cin>>n>>m>>l>>T;
//	dp[1][1]=1;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cin>>p[i][j];
//			if(p[i][j]<l){
//				dp[i][j]=dp[i-1][j]+dp[i][j-1];
//			}
//		}
//	}
	while(T--){
		int o,a,b,c,d,v;
		scanf("%d%d%d%d%d",&o,&a,&b,&c,&d);
		if(o==1){
			scanf("%d",&v);
			dif[a][b]+=v;
			dif[a][d+1]-=v;
			dif[c+1][b]-=v;
			dif[c+1][d+1]+=v;
		}else{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					dif[i][j]+=dif[i-1][j]+dif[i][j-1]-dif[i-1][j-1];
					p[i][j]+=dif[i][j];
					dp[i][j]=0;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(p[i][j]>=l || (p[i-1][j]>l && p[i][j-1]>l)){
						vis[i][j]=true;
					}
					dif[i][j]=0;
				}
			}
			if(vis[c][d]){
				cout<<"no"<<endl;
				continue;
			}
			if(p[a][b]<l){
				dp[a][b]=1;
			}else{
				cout<<"no"<<endl;
				continue;
			}
			for(int i=a;i<=c;i++){
				for(int j=b;j<=d;j++){
					if(i==a && j==b){
						continue;
					}
					if((dp[i-1][j]!=0 || dp[i][j-1]!=0) && p[i][j]<l){
						dp[i][j]=1;
					}
				}
			}
			if(dp[c][d]==1){
				cout<<"yes"<<endl;
			}else{
				cout<<"no"<<endl;
			}
		}
	}



	return 0;
}
/*
3 4 5 6
1 1 2 2 4 3
1 2 2 3 3 2
2 2 1 3 4
1 3 1 3 3 3
2 1 2 3 4
2 2 1 3 4
*/
