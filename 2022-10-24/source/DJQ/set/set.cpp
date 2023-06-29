#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
    int x = 0;
    char c = getchar();
    bool f = 0;
    while(!isdigit(c)) f |= (c == '-'), c = getchar();
    while(isdigit(c)) x = (x * 10) + (c ^ 48), c = getchar();
    return f ? -x : x;
}
const int maxn = 1e6 + 5, mod = 1e9 + 7;
int n;
int a[maxn], b[maxn], num[maxn], Answer, f[maxn];
inline bool Check() {
    fill(b, b + n + 1, 0);
    int tot = 0;
    for(register int i = 0; i <= n; ++i)
        if(a[i]) b[i] = 1, tot++;
    if(!tot) return 0;
    for(register int i = 0; i <= n; ++i) {
        if(!a[i]) continue;
        for(register int j = 0; j <= n; ++j)
            if(a[j] && !b[i ^ j]) return 0;
    }
    num[tot]++, Answer++;
    return 1;
}
inline void Search(int len) {
    if(len == n + 1) { Check(); return ; }
    a[len] = 0, Search(len + 1);
    a[len] = 1, Search(len + 1);
}
signed main() {
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
    n = read();
    if(n > 20) {
        int tot = 0;
        while(n) tot++, n >>= 1;
        f[1] = 1;
        for(register int i = 2; i <= tot; ++i) {
            int base = 2;
            for(register int j = 1; j <= i - 1; ++j)
                f[j] = (f[j] * base % mod + (j == 1 ? 1 : (1 << (i - 1)) - 1)) % mod, base <<= 1;
            f[i] = 1;
        }
        for(register int i = 1; i <= tot; ++i) Answer = (Answer + f[i]) % mod;
        Answer = (Answer + 1) % mod;
        printf("%lld\n", Answer);
        return 0;
   }
   Search(0);
   printf("%lld\n", Answer);
    return 0;
} 