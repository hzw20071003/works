#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n;
int find(int x){
    int cnt=0;
    while(x){
        int y=1<<(int)(log2(x));
        x-=y;
        ++cnt;
    }
    return cnt;
}
int qpow(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
namespace force{
    int ans;
    bool vis[35]={};
    bool check(){
        for(int i=0;i<=25;++i){
            for(int j=0;j<=25;++j){
                if(vis[i]&&vis[j]&&!vis[i^j])return 0;
            }
        }
        return 1;
    }
    void dfs(int x,int k){
        if(x==k){
            ans+=check();
            return;
        }
        dfs(x+1,k);
        vis[x]=1;
        dfs(x+1,k);
        vis[x]=0;
    }
    void Main(){
        cin>>n;
        ans=2;
        for(int i=2;i<=n;++i){
            vis[0]=vis[i]=1;
            dfs(1,i);
            vis[i]=0;
        }
        cout<<ans;
        return;
    }
}
signed main(){
    freopen("set.in","r",stdin);
    freopen("set.out","w",stdout);
    int ans=2;
    cin>>n;
    if(n<=23){
        force::Main();
        return 0;
    }
    for(int i=2;i<=n;++i)ans=(ans+qpow(2,(qpow(2,find(i)-1)-1)))%mod;
    cout<<ans;
    return 0;
}