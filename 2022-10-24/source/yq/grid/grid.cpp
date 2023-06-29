#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int n,m,l,cnt,Q,head[maxn];
long long v[maxn];
bool vis[maxn];
struct E{
    int to,next;
}edge[maxn<<3];
void add(int u,int v){
    edge[++cnt].to=v;edge[cnt].next=head[u];head[u]=cnt;
}
int id(int x,int y){
    return (x-1)*m+y;
}
pair<int,int> Reid(int x){
    int a,b;
    b=x%m;a=x/m;
    if(b==0)b=m;
    return {a,b};
}
bool dfs(int x,int flag){
    if(vis[x])return 0;
    if(flag==x)return 1;
    vis[x]=1;
    pair<int,int>a=Reid(x),f=Reid(flag);
    if(a.first>f.first||a.second>f.second)return 0;
    for(int i=head[x];i;i=edge[i].next){
        int y=edge[i].to;
        if(v[y]>=l)continue;
        if(dfs(y,flag))return 1;
    }
    return 0;
}
int main(){
    freopen("grid.in","r",stdin);
    freopen("grid.out","w",stdout);
    ios::sync_with_stdio(false);
    std::cin.tie(0);std::cout.tie(0);
    cin>>n>>m>>l>>Q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x,y;x=i+1,y=j;
            if(x<=n&&y<=m)add(id(i,j),id(x,y));
            x=i;y=j+1;
            if(x<=n&&y<=m)add(id(i,j),id(x,y));
        }
    }
    while(Q--){
        int op,a,b,c,d,val;
        cin>>op;
        if(op==1){
            cin>>a>>b>>c>>d>>val;
            for(int i=a;i<=c;i++){
                for(int j=b;j<=d;j++){
                    v[id(i,j)]+=val;
                }
            }
        }else{
            cin>>a>>b>>c>>d;
            memset(vis,0,sizeof(vis));
            if(dfs(id(a,b),id(c,d)))cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }
    }
    return 0;
}