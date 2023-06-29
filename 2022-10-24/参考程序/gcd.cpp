#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

const int MX = 100000;

int T,n,id;
int fa[MX + 5];

long long ans;

bool cnt[MX + 5];
bool mark[MX + 5];

int getroot(int p)
{
	return p == fa[p] ? p : fa[p] = getroot(fa[p]);
}

int main()
{
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout); 
	ios::sync_with_stdio(false);
	for (int i = 1;i <= MX;i++)
		fa[i] = i;
	cin >> n;
	for (int a,i = 1;i <= n;i++)
	{
		cin >> a;
		if (cnt[a])
			ans += a;
		cnt[a] = true;
	}
	for (int i = MX;i >= 1;i--)
	{
		int sum = 0;
		for (int j = i;j <= MX;j += i)
			if (cnt[j])
			{
				int r = getroot(j);
				if (!mark[r])
				{
					sum++;
					mark[r] = true;
				}
			}
		if (sum)
		{
			ans += (long long)(sum - 1) * i;
			for (int j = i;j <= MX;j += i)
				if (cnt[j])
				{
					int r = getroot(j);
					mark[r] = false;
					fa[r] = i;
				}
		}
	}
	cout << ans << endl;
	return 0;
}