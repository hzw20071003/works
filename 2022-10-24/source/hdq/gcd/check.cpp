#include<bits/stdc++.h>
using namespace std;
int n,a[100005],p[100005],sum;
bool vis[100005];
vector<int>b[100005],num[100005];
void work(int x){
    for(int i=2;i*i<=a[x];++i){
        if(a[x]%i!=0)continue;
        b[i].push_back(x);
        if(i*i!=a[x])b[a[x]/i].push_back(x);
        num[x].push_back(i);
        if(i*i!=a[x])num[x].push_back(a[x]/i);
        if(!vis[i])p[++sum]=i,vis[i]=1;
        if(!vis[a[x]/i])p[++sum]=a[x]/i,vis[a[x]/i]=1;
    }
    b[1].push_back(x);
    if(a[x]!=1)b[a[x]].push_back(x);
    num[x].push_back(1);
    if(a[x]!=1)num[x].push_back(a[x]);
    if(!vis[1])p[++sum]=1,vis[1]=1;
    if(!vis[a[x]])p[++sum]=a[x],vis[a[x]]=1;
    return;
}
// bool vis[100005];
int fa[100005],tot;
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void unionn(int a,int b){
    int x=find(a),y=find(b);
    if(x!=y)fa[x]=y;
    return;
}
struct node{
    int u,v,w;
}e[1000005];
bool cmp(node x,node y){
    return x.w>y.w;
}
int main(){
    freopen("duipai.ans","w",stdout);
    srand(time(0));
    int T=10000;
    int cnt=0;
    while(T--){
        n=1000;
        sum=0;
        memset(p,0,sizeof(p));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;++i)a[i]=1ll*rand()*rand()%100000+1,num[i].clear();
        for(int i=1;i<=100000;++i)b[i].clear();
        for(int i=1;i<=n;++i){
            work(i);
            fa[i]=i;
            sort(num[i].begin(),num[i].end());
        }
        sort(p+1,p+sum+1);
        int len=unique(p+1,p+sum+1)-p-1;
        sum=len;
        // for(int i=1;i<=n;++i){
        //     cout<<a[i]<<":  ";
        //     for(int j=0;j<num[i].size();++j)cout<<num[i][j]<<' ';
        //     cout<<'\n';
        // }
        long long ans1=0;
        for(int i=sum;i>=1;--i){
        // for(int j=0;j<b[p[i]].size();++j){
        //     for(int k=j+1;k<b[p[i]].size();++k){
        //         if(find(b[p[i]][j])!=find(b[p[i]][k])){
        //             unionn(b[p[i]][j],b[p[i]][k]);
        //             // cout<<"Success: "<<a[b[p[i]][j]]<<' '<<a[b[p[i]][k]]<<' '<<p[i]<<'\n';
        //             ans+=p[i];
        //         }
        //     }
        // }
        for(int j=0;j<b[p[i]].size();++j){
            // for(int k=j+1;k<b[p[i]].size();++k){
                if(find(b[p[i]][j])!=find(b[p[i]][0])){
                    unionn(b[p[i]][j],b[p[i]][0]);
                    // cout<<"Success: "<<a[b[p[i]][j]]<<' '<<a[b[p[i]][k]]<<' '<<p[i]<<'\n';
                    ans1+=p[i];
                }
            // }
        }
    }
        tot=0;
        for(int i=1;i<=n;++i)fa[i]=i;
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
        if(ans==ans1)printf("Accept on #%d\n",++cnt);
        else{
            printf("WA on test # %d\nTest data:\n",++cnt);
            cout<<n<<'\n';
            for(int i=1;i<=n;++i)cout<<a[i]<<' ';
            return 0;
        }
    }
    return 0;
}