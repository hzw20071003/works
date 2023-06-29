#include<bits/stdc++.h>
using namespace std;
int n=1000;
int ys(int x)
{
    int s=0;
    for(int i=1;i<=sqrt(x);i++)
        if(x%i==0)
            s+=2;
    return s;
}
int main()
{
    freopen("gcd.in","w",stdout);
    cout<<n<<endl;
    srand(time(NULL));
    for(int i=1;i<=n;i++)
        cout<<rand()*rand()%100000+1<<' ';
    return 0;
}