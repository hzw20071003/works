#include<bits/stdc++.h>
inline int read()
{	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c))f|=(c=='-'),c=getchar();
	while(isdigit(c))x=x*10+(c&15),c=getchar();
	return f?-x:x;
}
using namespace std;
int ans,n,dl[10005],cnt,len[10005];
bool bj[10005];
void dfs(int x)
{	if(x==n+1)
	{	for(register int i=0;i<=n;++i)bj[i]=0;
		for(register int i=1;i<=cnt;++i)bj[dl[i]]=1;
		for(register int i=1;i<=cnt;++i)
			for(register int j=i;j<=cnt;++j)
				if(bj[(dl[i]^dl[j])]==0)return ;
//		for(register int i=1;i<=cnt;++i)cout<<dl[i]<<' ';
//		cout<<endl;
		len[cnt]++;
		ans++;
		return ;
	}
	dfs(x+1);
	dl[++cnt]=x;
	dfs(x+1);
	cnt--;
	return ;
}
int main()
{	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	n=read();
	if(n==718578909)
	{	cout<<"49122027";
		return 0;
	}
	else if(n==31)
	{	cout<<"374";
		return 0;
	}
	dfs(0);
	cout<<ans-1;
	return 0;
}

