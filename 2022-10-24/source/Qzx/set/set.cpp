#include<bits/stdc++.h>
#define printsp(x) print(x),putchar(' ')
#define printen(x) print(x),putchar('\n')
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return x*f;
}
inline void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
const int N=1e5+9,mod=1e9+7;
int n,ans,H2SO4[N],HCl[N];
bool check(int x){
	for(int i=1;i<=x;i++)
		for(int j=i+1;j<=x;j++)
			if(!HCl[(H2SO4[i]^H2SO4[j])])return 0;
	return 1;
}
void dfs(int x){
	if(check(x-1)){
		ans=(ans+1)%mod;
//		for(int i=1;i<x;i++)cout<<H2SO4[i]<<" ";
//		cout<<endl;
	}
	for(int i=H2SO4[x-1]+1;i<=n;i++){
		if(HCl[i])continue;
		bool BaSO4=0;
		for(int j=1;j<x;j++)if((H2SO4[j]^i)>n){BaSO4=1;break;}
		if(!BaSO4){
			H2SO4[x]=i;
			HCl[i]=1;
			dfs(x+1);
			H2SO4[x]=0;
			HCl[i]=0;
		}
	}
}
signed main(){
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	n=read();
	HCl[0]=1;
	dfs(1);
	print(ans);
	return 0;
}
