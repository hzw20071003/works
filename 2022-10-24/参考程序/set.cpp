#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;

const int N=35;
const ll P=1e9+7;

int k,n;
int f[N][N][2];

inline ll pow(ll a,ll b,ll r=1) {
	if(b<0) return 0;
	while(b) {
		if(b&1) r=r*a%P;
		a=a*a%P;
		b>>=1;
	}
	return r;
}

int main() {
	freopen("set.in", "r", stdin);
	freopen("set.out", "w", stdout);
	cin>>k;
	if(k==0) {cout<<1;return 0;}
	for(n=30;;n--) if(k&(1<<n)) break;
//	cout<<"-->"<<n<<endl;
	f[n][0][0]=f[n][1][1]=1;
	for(int i=n-1;i>=0;i--) {
//		f[i][0][0]=1;
		for(int j=0;j<=n-i;j++) {
			f[i][j+1][0]=(f[i][j+1][0]+f[i+1][j][0])%P;
			f[i][j][0]=(f[i][j][0]+pow(2,j)*f[i+1][j][0])%P;
			if(k&(1<<i)) {
				f[i][j+1][1]=(f[i][j+1][1]+f[i+1][j][1])%P;
				f[i][j][0]=(f[i][j][0]+pow(2,j-1)*f[i+1][j][1])%P;
				f[i][j][1]=(f[i][j][1]+pow(2,j-1)*f[i+1][j][1])%P;
			}
			else {
				f[i][j][1]=(f[i][j][1]+pow(2,j-1)*f[i+1][j][1])%P;
			}
		}
	}
	ll ans=0;
	for(int j=0;j<=n+1;j++) ans=(ans+f[0][j][0]+f[0][j][1])%P;
	cout<<ans<<endl;
	return 0;
}