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
int n, m, L, q;
namespace Sub1 {
    const int maxn = 3005;
    int A[maxn][maxn], Vst[maxn][maxn], go[2][2] = {{0, 1}, {1, 0}};
    inline bool Search(int sx, int sy, int ex, int ey) {
        queue < pair<int, int> > Q;
        for(register int i = sx; i <= ex; ++i)
            for(register int j = sy; j <= ey; ++j) Vst[i][j] = 0;
        Q.push(make_pair(sx, sy)), Vst[sx][sy] = 1;
        while(!Q.empty()) {
            int x = Q.front().first, y = Q.front().second; Q.pop();
            if(x == ex && y == ey) { return 1; }
            for(register int i = 0; i < 2; ++i) {
                int nx = x + go[i][0], ny = y + go[i][1];
                if(nx < 1 || ny < 1 || nx > n || ny > m || A[nx][ny] >= L || Vst[nx][ny]) continue;
                Vst[nx][ny] = 1, Q.push(make_pair(nx, ny));
            }
        }
        return 0;
    }
    inline void Work() {
        while(q--) {
            int op = read(), a = read(), b = read(), c = read(), d = read();
            if(op == 1) {
                int v = read();
                for(register int i = a; i <= c; ++i)
                    for(register int j = b; j <= d; ++j) A[i][j] += v;
            }
            else {
                if(Search(a, b, c, d)) printf("yes\n");
                else printf("no\n");
            }
        }        
    }
}
int main() {
    freopen("grid.in", "r", stdin);
    freopen("grid.out", "w", stdout);
    n = read(), m = read(), L = read(), q = read();
    Sub1::Work();
    return 0;
}