#include <bits/stdc++.h>
using namespace std;
int n, a[100005];
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int fa[100005], ans;
int find(int cur)
{
    if (fa[cur] == cur)
        return cur;
    return fa[cur] = find(fa[cur]);
}
bool Union(int a, int b)
{
    if (find(a) == find(b))
        return false;
    fa[fa[a]] = fa[b];
    return true;
}
struct node
{
    int x, y, v;
} p[200005];
int cnt = 0;
bool cmp(node a, node b)
{
    return a.v > b.v;
}
void solve_1()
{
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        for (int j = 1; j <= n; j++)
        {
            p[++cnt] = (node){i, j, gcd(a[i], a[j])};
        }
    }
    sort(p + 1, p + cnt + 1, cmp);
    for (int i = 1; i <= cnt; i++)
    {
        if (Union(p[i].x, p[i].y))
            ans += p[i].v;
    }
    cout << ans << "\n";
}
int main()
{
    freopen("gcd.in", "r", stdin);
    freopen("gcd.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    solve_1();
    return 0;
}