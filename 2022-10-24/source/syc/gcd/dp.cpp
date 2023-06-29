#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T=0;
    while(++T)
    {
        system("gen.exe");
        system("std.exe");
        system("gcd.exe");
        if(system("fc gcd.out std.out"))
        {
            cout<<T<<":NO"<<endl;
            break;
        }
        cout<<T<<":YES"<<endl;
    }
    return 0;
}