#include<bits/stdc++.h>
#define printsp(x) print(x),putchar(' ')
#define printen(x) print(x),putchar('\n')

using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return x*f;
}
inline void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
const int N=1009;
int n,m,L,q,k[N][N],CuO;
void dfs(int x,int y,int c,int d){
	if(x==c&&y==d){
		CuO=1;
		return;
	}
	if(y+1<=d&&k[x][y+1]<L){
		dfs(x,y+1,c,d);
		if(CuO)return;
	}
	if(x+1<=c&&k[x+1][y]<L){
		dfs(x+1,y,c,d);
		if(CuO)return;
	}
	return;
}
signed main(){
	freopen("grid.in","r",stdin);
	freopen("grid.out","w",stdout);
	n=read(),m=read(),L=read(),q=read();
	while(q--){
		int op=read(),a=read(),b=read(),c=read(),d=read();
		if(op==1){
			int v=read();
			for(int i=a;i<=c;i++)
				for(int j=b;j<=d;j++)k[i][j]+=v;
		}
		else{
			CuO=0;
			if(k[c][d]>=L||a>c||b>d){puts("no");continue;}
			dfs(a,b,c,d);
			puts(CuO?"yes":"no");
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
