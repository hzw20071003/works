#include <bits/stdc++.h>
using namespace std;
// method 1
int k[405][405], n, m, q, l;
void add(int a, int b, int c, int d, int t)
{
    for (int i = a; i <= c; i++)
    {
        for (int j = b; j <= d; j++)
        {
            k[i][j] += t;
        }
    }
}
bool acc[405][405];
bool query(int a, int b, int c, int d)
{
    memset(acc, 0, sizeof(acc));
    acc[a][b] = (k[a][b] <= l);
    for (int i = a; i <= c; i++)
    {
        for (int j = b; j <= d; j++)
        {
            acc[i + 1][j] = acc[i + 1][j] || (acc[i][j] && k[i + 1][j] < l);
            acc[i][j + 1] = acc[i][j + 1] || (acc[i][j] && k[i][j + 1] < l);
        }
    }
    return acc[c][d];
}
// method 2
int tree[400005];
void push_up(int cur)
{
    tree[cur] = max(tree[cur * 2], tree[cur * 2 + 1]);
}
void update(int cur, int l, int r, int ql, int qr, int v)
{
    if (l > qr || r < ql)
        return;
    if (l == r)
    {
        tree[cur] += v;
        return;
    }
    int mid = (l + r) / 2;
    update(cur * 2, l, mid, ql, qr, v);
    update(cur * 2 + 1, mid + 1, r, ql, qr, v);
    push_up(cur);
    return;
}
int _query(int cur, int l, int r, int ql, int qr)
{
    if (l > qr || r < ql)
        return -1;
    if (l >= ql && r <= qr)
    {
        return tree[cur];
    }
    int mid = (l + r) / 2;
    return max(_query(cur * 2, l, mid, ql, qr), _query(cur * 2 + 1, mid + 1, r, ql, qr));
}
void solve()
{
    int opt, a, b, c, d, t;
    for (int i = 1; i <= q; i++)
    {
        cin >> opt >> a >> b >> c >> d;
        if (opt == 1)
        {
            cin >> t;
            update(1, 1, m, b, d, t);
        }
        else
        {
            int ans = _query(1, 1, m, b, d);
            if (ans < l)
                cout << "yes\n";
            else
                cout << "no\n";
        }
    }
}
int main()
{
    freopen("grid.in", "r", stdin);
    freopen("grid.out", "w", stdout);
    cin >> n >> m >> l >> q;
    if (n == 1)
        solve();
    int opt, a, b, c, d, t;
    for (int i = 1; i <= q; i++)
    {
        cin >> opt >> a >> b >> c >> d;
        if (opt == 1)
        {
            cin >> t;
            add(a, b, c, d, t);
        }
        else
        {
            if (query(a, b, c, d))
                cout << "yes\n";
            else
                cout << "no\n";
        }
    }
}