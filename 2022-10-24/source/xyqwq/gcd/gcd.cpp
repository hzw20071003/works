//gcd2
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int NUM=1e5+5;

int n,maxn,ans;
int a[NUM],num[NUM],fa[NUM];
bool bj[NUM];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

inline int findfa(int x)
{
    if(fa[x]==x)
        return x;
    return fa[x]=findfa(fa[x]);
}

signed main()
{
	freopen("gcd.in","r",stdin); 
	freopen("gcd.out","w",stdout); 
	
    n=read();
    for(int i=1;i<=n;++i)
    {
        a[i]=read();

        if(bj[a[i]])
        {
            ++num[a[i]];
        }
        else
        {
            ++num[a[i]];
            bj[a[i]]=1;
            fa[a[i]]=a[i];
        }

        maxn=max(maxn,a[i]);
    }

    for(int i=maxn;i>=1;--i)
    {
        int pre=0,temp=0,now=0;
        for(int j=i;j<=maxn;j+=i)
        {
            // cout<<"!!!"<<endl;
            if(!pre)
                pre=findfa(j);
            if(bj[j])
            {
                now=findfa(j);
                if(pre!=now)
                {
                    if(num[pre]>num[now])
                        fa[now]=pre;
                    else
                    {
                        ++temp;
                        fa[pre]=now;
                        pre=now;
                    }
                }
            }
        }
        if(bj[i])
            ans+=(temp+num[i]-1)*i;
        else
            ans+=temp*i;
    }

    // cout<<"!!!"<<endl;
    cout<<ans;

    return 0;
}
