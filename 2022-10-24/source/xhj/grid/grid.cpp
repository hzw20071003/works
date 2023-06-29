#include<bits/stdc++.h>
#define int long long 
using namespace std; 
int n,m,q,L,mp[505][505],F;
inline int read(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)) f|=(c=='-'),c=getchar();
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?-x:x;
}inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}void work(int x,int y,int l,int r){
	if(F){
		return ;
	}
	if(x>l||y>r){
		return ;
	}
	if(x==l&&y==r){
		cout<<"yes"<<endl;
		F=1;
		return ;
	}
	if(mp[x][y+1]<L){
		work(x,y+1,l,r);
	}if(mp[x+1][y]<L&&!F){
		work(x+1,y,l,r);
	} return ;
}void C(int x,int y,int l,int r,int N){
	for(int j=x;j<=l;j++){
		for(int i=y;i<=r;i++){
			mp[j][i]+=N;
		}
	}
}
signed main(){
	freopen("grid.in","r",stdin);
	freopen("grid.out","w",stdout);
	n=read(); m=read(); L=read(); q=read();
	for(int i=1;i<=q;i++){
		int sr=read(),x=read(),y=read(),l=read(),r=read();
		if(sr==2){
			work(x,y,l,r);
			if(!F){
				cout<<"no"<<endl;
			}
			F=0;
		}else{
			int N=read();
			C(x,y,l,r,N);
		}
	}
	return 0;
}	
/*
3 4 5 6
1 1 2 2 4 3
1 2 2 3 3 2
2 2 1 3 4
1 3 1 3 3 3
2 1 2 3 4
2 2 1 3 4

*/
