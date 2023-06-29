#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
int a[maxn];
struct node
{
    int x,y,w;
}e[maxn*maxn];
int n,tot=0;
int cmp(node s1,node s2)
{
    return s1.w>s2.w;
}
int fa[maxn];
int getfa(int x)
{
    return fa[x]==x?fa[x]:fa[x]=getfa(fa[x]);
}
int s=0;
int main()
{
    freopen("gcd.in","r",stdin);
    freopen("std.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            e[++tot].x=i;
            e[tot].y=j;
            e[tot].w=__gcd(a[i],a[j]);
        }
    }
    for(int i=1;i<=n;i++)
        fa[i]=i;
    sort(e+1,e+tot+1,cmp);
    int s=0;
    for(int i=1;i<=tot;i++)
    {
        int fx=getfa(e[i].x),fy=getfa(e[i].y);
        if(fx!=fy)
        {
            s+=e[i].w;
            fa[fx]=fy;
        }
    }
    cout<<s;
    return 0;
}