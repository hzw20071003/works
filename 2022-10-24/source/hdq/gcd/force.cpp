#include<bits/stdc++.h>
using namespace std;
struct node{
    int u,v,w;
}e[1000005];
int n,a[1005],tot;
int fa[100005];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void unionn(int a,int b){
    int x=find(a),y=find(b);
    if(x!=y)fa[x]=y;
    return;
}
bool cmp(node x,node y){
    return x.w>y.w;
}
int main(){
    freopen("gcd.in","r",stdin);
    freopen("gcd.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i],fa[i]=i;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            e[++tot]={i,j,__gcd(a[i],a[j])};
        }
    }
    sort(e+1,e+tot+1,cmp);
    long long ans=0;
    for(int i=1;i<=tot;++i){
        if(find(e[i].u)==find(e[i].v))continue;
        unionn(e[i].u,e[i].v);
        ans+=e[i].w;
    }
    cout<<ans;
    return 0;
}