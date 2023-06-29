#include<bits/stdc++.h>
#define int long long
inline int read()
{	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c))f|=(c=='-'),c=getchar();
	while(isdigit(c))x=x*10+(c&15),c=getchar();
	return f?-x:x;
}
using namespace std;
int n,m,l,q,ma[305][305],cf[100005];
bool bj[305][305],flag;
inline void check(int x,int y,int c,int d)
{	if(flag)return ;
	bj[x][y]=1;
	if(x==c&&y==d)
	{	flag=1;
		return ;
	}
	if(x+1<=c&&ma[x+1][y]<l&&bj[x+1][y]==0)check(x+1,y,c,d);
	if(y+1<=d&&ma[x][y+1]<l&&bj[x][y+1]==0)check(x,y+1,c,d);
	return ;
}
signed main()
{	freopen("grid.in","r",stdin);
	freopen("grid.out","w",stdout);
	n=read(),m=read(),l=read(),q=read();
	if(n==1)
	{	for(register int i=1;i<=q;++i)
		{	int op=read(),a=read(),b=read(),c=read(),d=read();
			if(op==1)
			{	int v=read();
				cf[b]+=v,cf[d+1]-=v; 
			}
			else
			{	int now=0;
				bool flag=1;
				for(register int i=1;i<=d;++i)
				{	now+=cf[i];
					if(i>=b&&now>=l)
					{	printf("no\n");
						flag=0;
						break;
					}
				}
				if(flag)printf("yes\n");
			}
		}
	}
	for(register int i=1;i<=q;++i)
	{	int op=read(),a=read(),b=read(),c=read(),d=read();
		if(op==1)
		{	int v=read();
			for(register int i=a;i<=c;++i)
				for(register int j=b;j<=d;++j)
					ma[i][j]+=v;
		}
		else
		{	for(register int i=a;i<=c;++i)
				for(register int j=b;j<=d;++j)
					bj[i][j]=0;
			flag=0;
			check(a,b,c,d);
			if(flag)printf("yes\n");
			else printf("no\n");
		}
	}
	return 0;
}

