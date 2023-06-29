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
int fa[100005];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void unionn(int a,int b){
    int x=find(a),y=find(b);
    if(x!=y)fa[x]=y;
    return;
}
long long ans=0;
int main(){
    freopen("gcd.in","r",stdin);
    freopen("gcd.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
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
    // for(int i=1;i<=sum;++i){
    //     cout<<p[i]<<":  ";
    //     for(int j=0;j<b[p[i]].size();++j)cout<<b[p[i]][j]<<' ';
    //     cout<<'\n';
    // }
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
                    ans+=p[i];
                }
            // }
        }
    }
    // for(int i=1;i<=n;++i){
    //     for(int j=num[i].size()-1;j>=0;j--){
    //         int k=num[i][j];
    //         bool flg=0;
    //         for(int p=0;p<b[k].size();++p){
    //             if(find(b[k][p])!=find(i)){
    //                 unionn(b[k][p],i);
    //                 ans+=k;
    //                 flg=1;
    //                 break;
    //             }
    //         }
    //         if(flg)break;
    //     }
    // }

    cout<<ans;
    // cout<<'\n'<<1.0*clock()/CLOCKS_PER_SEC;
    return 0;
}