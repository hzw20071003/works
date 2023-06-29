#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main() {
    int t = 10000;
    while(t--) {
        system("data.exe");
        system("std.exe");
        system("gcd.exe");
        if(system("fc std.out gcd.out") == 0) printf("AC!\n");
        else { printf("WA\n"); break; } 
    }
    return 0;
}
