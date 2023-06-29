#include<bits/stdc++.h>

using namespace std;
const int N(1e5+7);

int n,ans,tot,cnt,maxw,w[N],f[N];
vector<int>v[N];
struct Node{
	int a,b,w;
}E[(400*400+7)];
inline bool cmp(Node a,Node b){
	return a.w>b.w;
}
inline int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
inline void ksk1(){
	for(int i(0);i<tot&&cnt<n-1;i++){
		int x(find(E[i].a)),y(find(E[i].b));
		if(x==y)continue;
		f[x]=f[y]=min(x,y),ans+=E[i].w,cnt++;
	}
}
inline void ksk2(){
	for(int i(maxw);i>=1&&cnt<n-1;i--){
		for(int j(0);j<v[i].size()&&cnt<n-1;j++){
			for(int k(j+1);k<v[i].size()&&cnt<n-1;k++){
				int x(find(v[i][j])),y(find(v[i][k]));
				//cout<<v[i][j]<<' '<<v[i][k]<<'\n';
				if(x==y)continue;
				f[x]=f[y]=min(x,y),ans+=i,cnt++;
			}
		}
	}
}
inline int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
inline int read(){
	int r(0);
	char ch(getchar());
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')r=(r<<1)+(r<<3)+ch-'0',ch=getchar();
	return r;
}
/*
5
5 6 7 10 21
*/
int main(){
	freopen("gcd.in","r",stdin),freopen("gcd.out","w",stdout);
	n=read();
	for(int i(0);i<n;i++){
		maxw=max(maxw,w[i]=read()),f[i]=i;
	}
	if(n<=400){
		for(int i(0);i<n;i++){
			for(int j(i+1);j<n;j++){
				int d(gcd(w[i],w[j]));
				E[tot++]={i,j,d};
			}
		}
		sort(E,E+tot,cmp);
		ksk1();
		cout<<ans;
	}else{
		for(int i(0);i<n;i++){
			for(int j(1);j*j<=w[i];j++){
				if(w[i]%j==0){
					v[j].push_back(i);
					if(w[i]/j!=j)v[w[i]/j].push_back(i);
				}
			}
		}
		ksk2();
		cout<<ans;
	}
	return 0;
} 
