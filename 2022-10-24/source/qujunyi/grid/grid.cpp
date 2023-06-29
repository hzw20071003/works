#include <bits/stdc++.h>
using namespace std;
bool u = 0;
struct node{
    int u,x,y,xx,yy,p;
}a[100005];
int fa[100005];
int find(int x){
    if(fa[x]==x){
        return x;
    }
    return fa[x]=find(fa[x]);
}
int sum[305][305];
bool b[305][305];
int dx[2]={0,1};
int dy[2]={1,0};
    int n, m, l, q;
void dfs(int x,int y){
    b[x][y]=1;
    for(int i = 0;i < 2;i++){
        int sx = x+dx[i],sy = y+dy[i];
        if(sx>=1&&sx<=n&&sy>=1&&sy<=m&&b[sx][sy]==0&&sum[sx][sy]<l){
            dfs(sx,sy);
        }
    }
}
int main(){
freopen("grid.in","r",stdin);
freopen("grid.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m >> l >> q;
    for(int i = 1;i <= n*m;i++){
        fa[i]=i;
    }
    for(int i = 1;i <= q;i++){
        int x;
        cin >> x;
        a[i].u=x;
        if(x==1){
                cin >> a[i].x >> a[i].y >> a[i].xx >> a[i].yy >> a[i].p;
        
            for(int k = a[i].x;k<= a[i].xx;k++){
                for(int j = a[i].y;j <= a[i].yy;j++){
                    sum[k][j]+=a[i].p;
                }
            }
        }else{
                cin >> a[i].x >> a[i].y >> a[i].xx >> a[i].yy;
        
            for(int k = a[i].x;k<= a[i].xx;k++){
                for(int j = a[i].y;j <= a[i].yy;j++){
                    b[k][j]=0;
                }
            }
            dfs(a[i].x,a[i].y);
            if(b[a[i].xx][a[i].yy]==1){
                cout << "yes"<<endl;
            }else{
                cout << "no"<< endl;
            }
        }
    }
    return 0;
}