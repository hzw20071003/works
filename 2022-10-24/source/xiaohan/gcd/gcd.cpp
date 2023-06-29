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
int n,a[100005],q[200005],head,tail,fa[100005],len,bian;
long long ans;
vector<int> t[100005];
int find(int x){return fa[x]==x?fa[x]:fa[x]=find(fa[x]);}
inline void cf(int x)
{	tail=100000;
	head=tail+1;
	for(register int i=1;i<=sqrt(x);++i)
		if(x%i==0)
		{	head--,q[head]=i;
			if(x/i!=i)tail++,q[tail]=x/i;
		}
	return ;
} 
int main()
{	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	n=read();
	bian=n-1;
	for(register int i=1;i<=n;++i)
	{	a[i]=read();
		fa[i]=i;
		cf(a[i]);
		for(register int j=head;j<=tail;++j)t[q[j]].push_back(i);
	}
	for(register int i=100000;i>=1;--i)
	{	len=t[i].size();
		if(len==0)continue;
		for(register int j=1;j<len;++j)
		{	int fx=find(t[i][j-1]),fy=find(t[i][j]);
			if(fx!=fy)
			{	fa[fy]=fx;
				ans=ans+1ll*i;
				bian--;
				if(bian==0)
				{	cout<<ans;
					return 0;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
