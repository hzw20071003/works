#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("gcd.in", "w", stdout);
    srand(114514);
    int n = 100000;
    cout << n << endl;
    for (int i = 1; i <= n; i++) cout << llabs(rand() * rand()) % n + 1 << endl;
    return 0;
}