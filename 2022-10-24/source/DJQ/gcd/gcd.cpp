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
const int maxn = 1e5 + 5;
int n, len;
int a[maxn];
int Father[maxn], maxx, b[maxn], Answer;
inline int Find(int x) {
    if(Father[x] != x) return Father[x] = Find(Father[x]);
    return Father[x];
}
inline void Unnion(int x, int y) {
    int f1 = Find(x), f2 = Find(y);
    if(f1 != f2) Father[f2] = f1;
}
inline void MST() {
    for(register int i = maxx; i >= 1; --i) {
        int now = 0;
        for(register int j = 1; i * j <= maxx; ++j) 
            if(b[i * j]) {
                int x = Find(i * j);
                if(!now) now = x;
                else {
                    if(now == x) continue;
                    Answer += i, Unnion(now, x);
//                    printf("%d\n", i);
                }
            }
    }
}
signed main() {
    freopen("gcd.in", "r", stdin);
    freopen("gcd.out", "w", stdout);
    n = read();
    for(register int i = 1; i <= n; ++i) {
        a[i] = read(), maxx = max(maxx, a[i]);
        if(!b[a[i]]) b[a[i]] = 1, Father[a[i]] = a[i] ;
        else Answer += a[i];
    }
    MST();
    printf("%lld\n", Answer);
    return 0;
}