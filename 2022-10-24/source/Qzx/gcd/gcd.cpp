#include<bits/stdc++.h>
#define printsp(x) print(x),putchar(' ')
#define printen(x) print(x),putchar('\n')
#define int long long
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
const int N=1e5+9;
int n,a[N],ans,CuSO4,AgNO3,CaCO3[N],FeCl3,NH3[N],NaOH[N];
vector<int>NaCl[N];
int NH4NO3(int x){return NH3[x]==x?x:NH3[x]=NH4NO3(NH3[x]);}
signed main(){
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)NH3[i]=i;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		CuSO4=max(CuSO4,a[i]);
		for(int j=1;j<(int)sqrt(a[i]);j++){
			if(a[i]%j)continue;
			CaCO3[j]++,CaCO3[a[i]/j]++;
			NaCl[j].push_back(i),NaCl[a[i]/j].push_back(i);
		}
		if((int)sqrt(a[i])*(int)sqrt(a[i])==a[i])CaCO3[(int)sqrt(a[i])]++,NaCl[(int)sqrt(a[i])].push_back(i);
		else if(a[i]%((int)sqrt(a[i]))==0)CaCO3[(int)sqrt(a[i])]++,NaCl[(int)sqrt(a[i])].push_back(i),CaCO3[a[i]/(int)sqrt(a[i])]++,NaCl[a[i]/(int)sqrt(a[i])].push_back(i);;
	}
	n--;
	for(int i=CuSO4;i>=1;i--){
		if(CaCO3[i]<=1)continue;
		int KCl=0,Fe3O4=0,MnO2[N];
		for(int j=0;j<NaCl[i].size();j++){
			if(NaOH[NaCl[i][j]])MnO2[++KCl]=NaCl[i][j];
			NaOH[NaCl[i][j]]=1;
		}
		for(int j=1;j<=KCl;j++)
			for(int k=j+1;k<=KCl;k++)if(__gcd(MnO2[j],MnO2[k])>i)Fe3O4++;
		Fe3O4=NaCl[i].size()-Fe3O4;
		Fe3O4=(Fe3O4*(Fe3O4-1))/2;
		if(Fe3O4<n)ans+=Fe3O4*i,n-=Fe3O4;
		else{ans+=n*i;break;}
	}
	print(ans);
	return 0;
}
/*
5
5 6 7 10 21
*/
