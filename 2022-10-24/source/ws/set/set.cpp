#include<bits/stdc++.h>
using namespace std;
int c[30],ans,n;
void dfs(int step){
	if(step>n){
		int ok=0;
		for(int i=0;i<=n;i++){
			if(c[i]){
				ok=1;
				for(int j=i;j<=n;j++){
					if(c[j] && !c[i^j]){ok=0;break;}
				}
				if(!ok)break;
			}
		}
		ans+=ok;
		return;
	}
	c[step]=0;dfs(step+1);c[step]=1;dfs(step+1);
}
int main(){
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	cin>>n;
	c[0]=1;
	dfs(1);
	cout<<ans;
	return 0;
}
