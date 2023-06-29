#include<bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0;
    char c = getchar();
    bool f = 0;
    while(!isdigit(c)) f |= (c == '-'), c = getchar();
    while(isdigit(c)) x = (x * 10) + (c ^ 48), c = getchar();
    return f ? -x : x;
}
const int mod = 1e5;
int n;
int main() {
    freopen("gcd.in", "w", stdout);
    srand(time(0));
    n = 1000;
    printf("%d\n", n);
    for(register int i = 1; i <= n; ++i) {
        int x = rand() % mod * rand() % mod % mod;
        while(!x) x = rand() % mod * rand() % mod % mod;
        printf("%d ", x);
    }
    return 0;
}