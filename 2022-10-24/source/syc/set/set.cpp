#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int n;
int ksm(int x,int y)
{
    int s=1;
    while(y)
    {
        if(y&1)
            s*=x,s%=mod;
        x*=x;
        x%=mod;
        y>>=1;
    }
    return s;
}
int f[10005],l[10005];
int can[10005];
int popcnt(int x)
{
    int s=0;
    while(x)
    {
        ++s;
        x-=(x&-x);
    }
    return s;
}
int b[100005],mp[100005];
signed main()
{
    freopen("set.in","r",stdin);
    freopen("set.out","w",stdout);
    cin>>n;
    int ff=0;
    for(int i=0;i<=31;i++)
        if((1<<i)-1==n)
            ff=1;
    if(n<=20)
    {
        int t=0,s=0;
        while(t<=n)
        {
            can[t+1]=1;
            t<<=1;
            t|=1;
        }
        for(int i=0;i<=(1<<n+1)-1;i++)
        {
            if(can[popcnt(i)])
            {
                int tot=0;
                for(int j=0;j<=n;j++)
                {   
                    mp[j]=0;
                    if((1<<j)&i)
                        b[++tot]=j,mp[j]=1;
                }
                int f=0;
                for(int i=1;i<=tot;i++)
                    for(int j=1;j<=tot;j++)
                        if(!mp[b[i]^b[j]])
                            f=1; 
                if(!f)
                {
                    ++s; 
                    s%=mod;
                } 
            }
        }
        cout<<s<<endl;
    }
    else if(ff)
    {
        l[0]=0;
        f[0]=1;
        l[1]=1;
        f[1]=n;
        int s=1+n;
        for(int i=2;;i++)
        {
            l[i]=l[i-1]*2+1;
            // cout<<l[i]<<endl;
            if(l[i]>n)
                break;
            f[i]=f[i-1]*((n-l[i-1]+mod)%mod)%mod*ksm(((l[i]+1)/2)*l[i]%mod,mod-2)%mod;
            s+=f[i];
            s%=mod;
        }
        cout<<s;
    }
    return 0;
}