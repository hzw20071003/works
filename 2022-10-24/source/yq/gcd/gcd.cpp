#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int n,a[maxn],p[maxn],f[maxn],tot;
vector<int>b[maxn];
map<pair<int,int>,bool>m;
long long ans;
int find(int x){
    if(x==f[x])return f[x];
    else return f[x]=find(f[x]);
}
int main(){
    freopen("gcd.in","r",stdin);
    freopen("gcd.out","w",stdout);
    ios::sync_with_stdio(false);
    std::cin.tie(0);std::cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)p[a[i]]=i,f[i]=i;
    for(int i=1;i<=a[n];i++){
        for(int j=i;j<=a[n];j+=i){
            if(p[j])b[i].push_back(p[j]);
        }
    }
    for(int i=a[n];i>=1;i--){
        if(b[i].size()<2)continue;
        for(int j=0;j<b[i].size();j++){
            for(int k=j+1;k<b[i].size();k++){
                int x=b[i][j],y=b[i][k];
                if(m[{x,y}])continue;
                m[{x,y}]=1;
                int fx=find(x),fy=find(y);
                if(fx==fy)continue;
                f[fx]=fy;tot++;
                ans+=i;
                if(tot==n-1){cout<<ans;return 0;}
            }
        }
    }
    cout<<ans;
    return 0;
}