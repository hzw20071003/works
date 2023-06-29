#include <bits/stdc++.h>
using namespace std;
int n, ans;
int gt[1000];
void check()
{
    for (int i = 1; i <= n; i++)
    {
        if (!gt[i])
            continue;
        for (int j = 1; j <= n; j++)
        {
            if (!gt[j])
                continue;
            if (!gt[i ^ j])
                return;
        }
    }
    ans = (ans + 1) % 1000000007;
    return;
}
void dfs(int cur)
{
    if (cur == n + 1)
    {
        check();
        return;
    }
    for (int i = cur; i <= n; i++)
    {
        gt[i] = 1;
        dfs(i + 1);
        gt[i] = 0;
    }
    return;
}
int main()
{
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
    cin >> n;
    dfs(0);
    cout << ans;
    return 0;
}