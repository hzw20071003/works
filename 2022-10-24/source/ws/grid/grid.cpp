#include<bits/stdc++.h>
using namespace std;
struct node{
	int ls,rs,l,r;
	long long tag,minn,maxn;
}t[800005];
#define lp t[p].ls
#define rp t[p].rs
int nnode(){static int cnt=0;return ++cnt;}

void build(int &p,int l,int r){
	p=nnode();
	t[p].minn=t[p].maxn=t[p].tag=0;
	t[p].l=l,t[p].r=r;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(lp,l,mid);build(rp,mid+1,r);
}

void pushup(int p){
	t[p].minn=min(t[lp].minn,t[rp].minn);
	t[p].maxn=max(t[lp].maxn,t[rp].maxn);
}
void pushdown(int p){
	if(t[p].tag){
		t[lp].tag+=t[p].tag,t[rp].tag+=t[p].tag;
		t[lp].minn+=t[p].tag,t[rp].minn+=t[p].tag;
		t[lp].maxn+=t[p].tag,t[rp].maxn+=t[p].tag;
		t[p].tag=0;
	}
}

void change(int p,int l,int r,int val){
	if(l<=t[p].l && t[p].r<=r){
		t[p].minn+=val,t[p].maxn+=val,t[p].tag+=val;
		return;
	}
	pushdown(p);
	int mid=(t[p].l+t[p].r)>>1;
	if(l<=mid)change(lp,l,r,val);
	if(mid<r)change(rp,l,r,val);
	pushup(p);
}

int L;
int R_query(int p,int l,int r){
	if(t[p].l==t[p].r)return p;
	pushdown(p);
	int mid=(t[p].l+t[p].r)>>1;
	if(r<=mid)return R_query(lp,l,r);
	else if(mid<l)return R_query(rp,l,r);
	else{
		int ll=R_query(lp,l,r),rr=R_query(rp,l,r);
		if(t[ll].maxn>=L)return ll;
		else return rr;
	}
}
int R_queryy(int p){
	if(t[p].l==t[p].r)return t[p].maxn>=L?t[p].l:-1;
	pushdown(p);
	if(t[lp].maxn>=L)return R_queryy(lp);
	else return R_queryy(rp);
}
int L_query(int p,int l,int r){
	if(t[p].l==t[p].r)return p;
	pushdown(p);
	int mid=(t[p].l+t[p].r)>>1;
	if(r<=mid)return L_query(lp,l,r);
	else if(mid<l)return L_query(rp,l,r);
	else{
		int ll=L_query(lp,l,r),rr=L_query(rp,l,r);
		if(t[ll].minn>=L){
			if(t[rr].maxn<L)return ll;
			else return rr;
		}
		else return ll;
	}
}
int L_queryy(int p){
	if(t[p].l==t[p].r)return t[p].maxn>=L?t[p].l:-1;
	pushdown(p);
	if(t[lp].minn>=L){
		if(t[rp].maxn<L)return L_queryy(lp);
		else return L_queryy(rp);
	}
	else return L_queryy(lp);
}
int segroot[320];
#undef lp
#undef rp
int fr();
int n,m,isrev,q;
int main(){
	freopen("grid.in","r",stdin);
	freopen("grid.out","w",stdout);
	
	n=fr();m=fr();L=fr();q=fr();
	if(n<m)swap(n,m),isrev=1;
	for(int i=1;i<=m;i++)build(segroot[i],1,n);
	for(int op,a,b,c,d,v;q;q--){
		op=fr();a=fr();b=fr();c=fr();d=fr();
		if(isrev)swap(a,b),swap(c,d);
		swap(b,c);
		if(op==1){
			v=fr();
			for(int i=c;i<=d;i++)change(segroot[i],a,b,v);
		}
		else{
			int upp=a,downn=b,now;
			int ok=1;
//			cerr<<"Q:"<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
			for(int i=c;i<=d;i++){
//				cerr<<"upp downn:"<<upp<<' '<<downn<<endl;
				now=L_queryy(L_query(segroot[i],upp,b));
				if(i==c && now!=-1){ok=0;break;}
				if(now!=-1)upp=now+1;
//				cerr<<now<<' '<<upp<<' '<<downn<<endl;
				now=R_queryy(R_query(segroot[i],upp,downn));
				if(now!=-1)downn=now-1;
				else{
					now=R_queryy(R_query(segroot[i],upp,b));
					if(now!=-1)downn=now-1;
					else downn=b;
				}
				cerr<<now<<' '<<upp<<' '<<downn<<endl;
				if(upp>downn){ok=0;break;}
			}
			if(ok)printf("yes\n");
			else printf("no\n");
		}
	}
	return 0;
}
int fr(){
	int x=0;char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c&15,c=getchar();
	return x;
}
