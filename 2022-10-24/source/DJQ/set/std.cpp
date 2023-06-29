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
const int maxn = 1e6 + 5;
int n;
int a[maxn], b[maxn], num[maxn], Answer;
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
    num[tot]++;
    return 1;
}
inline void Out() {
    for(register int i = 0; i <= n; ++i)
        if(a[i]) printf("%d ", i);
    Answer++;
    printf("\n");
}
inline void Search(int len) {
    if(len == n + 1) {
        if(Check()) Out();
        return ;
    }
    a[len] = 0, Search(len + 1);
    a[len] = 1, Search(len + 1);
}
int main() {
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
    n = read();
    Search(0);
    printf("%d\n", Answer);
    for(register int i = 1; i <= n + 1; ++i) printf("%d ", num[i]);
    return 0;
} 