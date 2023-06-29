#include<bits/stdc++.h>
using namespace std;
vector<int> v[100005];
int fa[100005];
int find(int x){
    if(fa[x]==x){
        return x;
    }
    return fa[x]=find(fa[x]);
}
int upp = 0;
int main(){
freopen("gcd.in","r",stdin);
freopen("gcd.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        int x;
        cin >> x;
        v[x].push_back(i);
        fa[i]=i;
    }
    long long sum = 0;
    for(int i = 100002;i >= 1;i--){
        if(upp==n-1){
            break;
        }
        bool s = 0;
        int u = 0;
        for(int j = 1;j * i <= 100002;j++){
            if(s == 0&&v[j*i].size()>=1){
                s=1;
                u = v[j*i][0];
                break;
            }
        }
        if(s==0){
            continue;
        }
        for(int j = 1;j * i <= 100002;j++){
                for(int k = 0;k < v[j*i].size();k++){
                    int fx = find(u),fy = find(v[j*i][k]);
                    if(fx!=fy){
                        sum+=i;
                        upp++;
                        fa[fx]=fy;
                    }
                }
        }
    }
    cout << sum;
}