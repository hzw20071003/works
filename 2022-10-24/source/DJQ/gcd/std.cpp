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
const int maxn = 2005;
int n, len;
int a[maxn];
struct node {
    int u, v, w;
}Line[maxn * maxn];
int Father[maxn];
inline bool operator <(node x, node y) { return x.w > y.w; }
inline void make_map(int u, int v, int w) {
    len++;
    Line[len].u = u;
    Line[len].v = v;
    Line[len].w = w;
}
inline int Find(int x) {
    if(Father[x] != x) return Father[x] = Find(Father[x]);
    return Father[x];
}
inline void Unnion(int x, int y) {
    int f1 = Find(x), f2 = Find(y);
    if(f1 != f2) Father[f2] = f1;
}
inline void MST() {
    int tot = 0, Answer = 0;
    for(register int i = 1; i <= len; ++i) {
        int u = Find(Line[i].u), v = Find(Line[i].v), w = Line[i].w;
        if(u != v) {
            Unnion(u, v);
            Answer += w, tot++;
//            printf("%lld %lld %lld\n", Line[i].u, Line[i].v, Line[i].w);
            if(tot == n - 1) break;
        }
    }
    printf("%lld\n", Answer);
}
signed main() {
    freopen("gcd.in", "r", stdin);
    freopen("std.out", "w", stdout);
    n = read();
    for(register int i = 1; i <= n; ++i) a[i] = read(), Father[i] = i;
    for(register int i = 1; i <= n; ++i)
        for(register int j = 1; j <= n; ++j) {
            int u = i, v = j, w = __gcd(a[i], a[j]);
            make_map(u, v, w);
        }
    sort(Line + 1, Line + len + 1);
    MST();
    return 0;
}