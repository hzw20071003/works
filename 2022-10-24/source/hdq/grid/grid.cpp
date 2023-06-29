#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,l,q;
namespace sub_with_n_equals_to_1{
    int tree[400005]={},tag[400005]={};
    void push_up(int cur){
        tree[cur]=max(tree[cur<<1],tree[cur<<1|1]);
        return;
    }
    void addtag(int cur,int lt,int rt,int val){
        tag[cur]+=val;
        tree[cur]+=val;
        return;
    }
    void push_down(int cur,int lt,int rt){
        if(!tag[cur])return;
        int mid=lt+rt>>1;
        addtag(cur<<1,lt,mid,tag[cur]);
        addtag(cur<<1|1,mid+1,rt,tag[cur]);
        tag[cur]=0;
        push_up(cur);
    }
    int query(int cur,int lt,int rt,int qx,int qy){
        if(lt>qy||rt<qx)return 0;
        if(qx<=lt&&rt<=qy)return tree[cur];
        push_down(cur,lt,rt);
        int mid=lt+rt>>1;
        return max(query(cur<<1,lt,mid,qx,qy),query(cur<<1|1,mid+1,rt,qx,qy));
    }
    void update(int cur,int lt,int rt,int qx,int qy,int val){
        if(lt>qy||rt<qx)return;
        if(qx<=lt&&rt<=qy){
            addtag(cur,lt,rt,val);
            return;
        }
        push_down(cur,lt,rt);
        int mid=lt+rt>>1;
        update(cur<<1,lt,mid,qx,qy,val);
        update(cur<<1|1,mid+1,rt,qx,qy,val);
        push_up(cur);
        return;
    }
    void Main(){
        // cin>>n>>m>>l>>q;
        // for(int i=1;i<=m;++i)cin>>a[i];
        for(int i=1;i<=q;++i){
            int opt;
            cin>>opt;
            if(opt==1){
                int a,b,c,d,v;
                cin>>a>>b>>c>>d>>v;
                update(1,1,m,b,d,v);
            }
            else{
                int a,b,c,d;
                cin>>a>>b>>c>>d;
                int k=query(1,1,m,b,d);
                // cout<<b<<' '<<d<<' '<<k<<'\n';
                if(k>=l)cout<<"no\n";
                else cout<<"yes\n";
            }
        }
    }
}
namespace force{
    int a[305][305]={};
    bool vis[305][305]={};
    int dx[2]={0,1};
    int dy[2]={1,0};
    bool bfs(int sx,int sy,int A,int b,int c,int d){
        queue<pair<int,int> >q;
        memset(vis,0,sizeof(vis));
        vis[sx][sy]=1;
        q.push(make_pair(sx,sy));
        if(a[sx][sy]>=l)return 0;
        while(!q.empty()){
            int x=q.front().first,y=q.front().second;
            q.pop();
            if(x==c&&y==d)return 1;
            for(int i=0;i<=1;++i){
                int nx=x+dx[i],ny=y+dy[i];
                if(nx<A||ny<b||nx>c||ny>d||vis[nx][ny]||a[nx][ny]>=l)continue;
                vis[nx][ny]=1;
                q.push(make_pair(nx,ny));
            }
        }
        return 0;
    }
    void MaiN(){
        for(int i=1;i<=q;++i){
            int opt;
            cin>>opt;
            if(opt==1){
                int A,b,c,d,v;
                cin>>A>>b>>c>>d>>v;
                for(int j=A;j<=c;++j){
                    for(int k=b;k<=d;++k){
                        a[j][k]+=v;
                    }
                }
            }
            else{
                int A,b,c,d;
                cin>>A>>b>>c>>d;
                bool k=bfs(A,b,A,b,c,d);
                if(k==0)cout<<"no\n";
                else cout<<"yes\n";
            }
        }
    }
}
signed main(){
    freopen("grid.in","r",stdin);
    freopen("grid.out","w",stdout);
    cin>>n>>m>>l>>q;
    if(n==1)sub_with_n_equals_to_1::Main();
    else force::MaiN();
    return 0;
}