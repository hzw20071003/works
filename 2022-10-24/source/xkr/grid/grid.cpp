#include<bits/stdc++.h>
using namespace std;
int n, m, l, q;
struct Sub1 {
    int x[305][305];
    int dp[305][305];
    void update(int a, int b, int c, int d, int val) {
        for (int i = a; i <= c; i++)
            for (int j = b; j <= d; j++)
                x[i][j] += val;
    }
    int query(int a, int b, int c, int d) {
        memset(dp, 0x3f, sizeof(dp)); dp[a - 1][b] = dp[a][b - 1] = 0;
        for (int i = a; i <= c; i++)
            for (int j = b; j <= d; j++)
                dp[i][j] = max(x[i][j], min(dp[i][j - 1], dp[i - 1][j]));
        return dp[c][d] < l;
    }
    void work() {
        for (int i = 1; i <= q; i++) {
            int p, a, b, c, d, v; cin >> p >> a >> b >> c >> d;
            if (p == 1) {cin >> v; update(a, b, c, d, v);}
            else if (query(a, b, c, d)) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
} s1;
struct Sub2 {
    #define ls (k << 1)
    #define rs (k << 1 | 1)
    #define mid (l + r >> 1)
    int a[100005];
    struct SegTree {
        int sum[400005], tag[400005];
        void pushup(int k) {sum[k] = max(sum[ls], sum[rs]);}
        void addtag(int k, int l, int r, int val) {tag[k] += val; sum[k] += val;}
        void pushdown(int k, int l, int r) {
            if (tag[k]) {
                addtag(ls, l, mid, tag[k]); addtag(rs, mid + 1, r, tag[k]);
                tag[k] = 0;
            }
        }
        void update(int k, int l, int r, int qx, int qy, int val) {
            if (l > qy || r < qx) return;
            if (qx <= l && qy >= r) {addtag(k, l, r, val); return;}
            pushdown(k, l, r);
            update(ls, l, mid, qx, qy, val); update(rs, mid + 1, r, qx, qy, val);
            pushup(k);
        }
        int query(int k, int l, int r, int qx, int qy) {
            if (l > qy || r < qx) return -1e9;
            if (qx <= l && qy >= r) return sum[k];
            pushdown(k, l, r);
            return max(query(k, ls, mid, qx, qy), query(rs, mid + 1, r, qx, qy));
        }
    } t;
    void work() {
        for (int i = 1; i <= q; i++) {
            int p, a, b, c, d, v; cin >> p >> a >> b >> c >> d;
            if (p == 1) {cin >> v; t.update(1, 1, m, b, d, v);}
            else if (t.query(1, 1, m, b, d) < l) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
} s2;
int main() {
    freopen("grid.in", "r", stdin);
    freopen("grid.out", "w", stdout);
    cin >> n >> m >> l >> q;
    if (n == 1) s2.work();
    else s1.work();
    return 0;
}