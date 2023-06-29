#include<bits/stdc++.h>
using namespace std;

int isp[100005],pri[100005],pcnt;
void init_pri(){
	isp[1]=1;
	for(int i=2;i<=100000;i++){
		if(!isp[i])pri[++pcnt]=i;
		for(int j=1;j<=pcnt && pri[j]*i<=100000;j++){
			isp[i*pri[j]]=1;
			if(i%pri[j]==0)continue;
		}
	}
}

int f[100005];
void init_f(int n){for(int i=1;i<=n;i++)f[i]=i;}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}

int n,p[35],c[35],cnt;
vector<int>d[100005];
void dfs(int step,int sum,int id){
	if(step>cnt){d[sum].push_back(id);return;}
	dfs(step+1,sum,id);
	for(int i=1;i<=c[step];i++){
		sum*=p[step];
		dfs(step+1,sum,id);
	}
}
int t[100005];
int main(){
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	cin>>n;
	init_pri();init_f(n);
	int maxv=0;
	for(int i=1,x;i<=n;i++){
		cin>>x;maxv=max(maxv,x);
		cnt=0;
		for(int j=1;pri[j]*pri[j]<=x && j<=pcnt;j++){
			if(!isp[x])break;
			if(x%pri[j]==0){
				cnt++;
				p[cnt]=pri[j],c[cnt]=0;
				while(x%pri[j]==0)x/=pri[j],c[cnt]++;
			}
		}
		if(!isp[x]){
			cnt++;
			p[cnt]=x,c[cnt]=1;
		}
		dfs(1,1,i);
	}
	long long ans=0;
	vector<int>now;
	for(int i=maxv;i;i--){
		if(d[i].size()<=1)continue;
		now.clear();
		int sum=0;
		for(int j=d[i].size()-1;j>=0;j--){
			int fx=find(d[i][j]);
			if(!t[fx])t[fx]=1,sum++,now.push_back(fx);
		}
		ans=ans+1LL*(sum-1)*i;
		for(int i=now.size()-1;i;i--){
			f[now[i]]=now[0];
			t[now[i]]=0;
		}
		t[now[0]]=0;
	}
	cout<<ans;
	return 0;
}
