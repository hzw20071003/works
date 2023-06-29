#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
bool wz1;
int n,a[maxn];
int fa[maxn];
int getfa(int x)
{
    return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
int ma=0;
vector<int> yz[maxn];
int bk[maxn];
signed main()
{
    freopen("gcd.in","r",stdin);
    freopen("gcd.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    { 
        cin>>a[i];
        ma=max(ma,a[i]);
        for(int j=1;j<=sqrt(a[i]);j++)
        {
            if(a[i]%j==0)
            { 
                yz[j].push_back(i);
                yz[a[i]/j].push_back(i);
            }
        }
    }
    for(int i=1;i<=n;i++)
        fa[i]=i;
    int s=0;
    for(int i=ma;i>=1;i--)
    {
        if(yz[i].empty())
            continue;
        int tot=0;
        for(int j=0;j<yz[i].size();j++)
        {
            int x=yz[i][j];
            int fx=getfa(fa[x]);
            if(!bk[fx])
                bk[fx]=1,++tot;
        }
        s+=(tot-1)*i;
        for(int j=0;j<yz[i].size();j++)
        {
            int x=yz[i][j];
            int fx=getfa(fa[x]);
            bk[fx]=0;
        }
        int tx=getfa(yz[i][0]);       
        for(int j=1;j<yz[i].size();j++)
            fa[getfa(yz[i][j])]=tx;
    }
    cout<<s<<endl;
    // bool wz2;
    // cout<<((&wz2)-(&wz1))/1024/1024;
    return 0;
}