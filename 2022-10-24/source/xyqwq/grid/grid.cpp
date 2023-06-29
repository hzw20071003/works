//grid
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int NUM=1e5+5;

int n,m,pp,qq;
int t[NUM];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

inline int lowbit(int x)
{
    return  x&(-x);
}

inline void update(int x,int num)
{
	while(x<=m)
	{
		t[x]+=num;
		x+=lowbit(x);
	}
}

inline int ask(int x)
{
	int res=0;
	while(x)
	{
		res+=t[x];
		x-=lowbit(x);
	}
	return res;
}

inline int query(int l,int r)
{
	int res=0;

	while(r>=l && r-l+1>=lowbit(r))
	{
		res=max(res,t[r]);
		r-=lowbit(r);
		// cout<<l<<" #@# "<<r<<endl;
	}

	while(r>=l)
	{
		res=max(res,ask(r));
		// cout<<r<<" "<<ask(r)<<endl;
		if(r-l+1<lowbit(r))
			--r;
		else
		{
			res=max(res,t[r]);
			r-=lowbit(r);
		}
	}

	return res;
}

signed main()
{
	freopen("grid.in","r",stdin); 
	freopen("grid.out","w",stdout); 
	
	n=read(),m=read(),pp=read(),qq=read();
	// if(n==1)
	// {
		while(qq--)
		{
			int op,a,b,c,d,v;
			op=read();
			if(op==1)
			{
				a=read(),b=read(),c=read(),d=read(),v=read();
				
				update(b,v);
				update(d+1,-v);
			}
			else if(op==2)
			{
				a=read(),b=read(),c=read(),d=read();
				// cout<<query(b,d)<<" "<<pp<<endl;
				if(query(b,d)<pp)
					cout<<"yes"<<endl;
				else
					cout<<"no"<<endl;
			}
		}
	// }
	// else
	// {
	// 	while(qq--)
	// 	{
	// 		int op,a,b,c,d,v;
	// 		op=read();
	// 		if(op==1)
	// 		{
	// 			a=read(),b=read(),c=read(),d=read(),v=read();
	// 		}
	// 		else if(op==2)
	// 		{
	// 			a=read(),b=read(),c=read(),d=read();
	// 		}
	// 	}
	// }

    return 0;
}
