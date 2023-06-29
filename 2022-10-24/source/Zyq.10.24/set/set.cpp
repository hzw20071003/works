#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
	int r(0);
	char ch(getchar());
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')r=(r<<1)+(r<<3)+ch-'0',ch=getchar();
	return r;
}
int n;
set<set<int> >s[16];
signed main(){
	freopen("set.in","r",stdin),freopen("set.out","w",stdout);
	n=read();
	s[0].insert({0});
	for(int i(1);i<=n;i++){
		s[i]=s[i-1];
		 for(auto j(s[i-1].begin());j!=s[i-1].end();j++){
		 	set<int>p(*j);
		 	for(auto k(j->begin());k!=j->end();k++){
		 		p.insert((*k)^i);
		 	}
		 	s[i].insert(p);
		 }
	}
	cout<<s[n].size();
	return 0;
} 
