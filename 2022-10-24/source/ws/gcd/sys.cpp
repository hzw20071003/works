#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("system.out","w",stdout);
	int tot=0;
	while(1){
		system("gen.exe");
		system("dp.exe");
		system("gcd.exe");
		if(system("fc dp.out gcd.out")){
			cerr<<"WA!";
			return 0;
		}
		tot++;
		cerr<<"GCD Case "<<tot<<": OK.\n";
	}
	return 0;
}
