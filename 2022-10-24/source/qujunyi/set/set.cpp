#include <bits/stdc++.h>
using namespace std;
int n;
bool b[25];
int sum = 0;
void dfs(int x)
{
    if (x == n + 1)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (b[i] == 1 && b[j] == 1 && b[(i ^ j)] != 1)
                {
                    return;
                }
            }
        }
        sum++;
        return;
    }
    b[x] = 1;
    dfs(x + 1);
    b[x] = 0;
    dfs(x + 1);
}
int main()
{
freopen("set.in","r",stdin);
freopen("set.out","w",stdout);
    cin >> n;
    b[0] = 1;
    dfs(1);
    cout << sum;
}