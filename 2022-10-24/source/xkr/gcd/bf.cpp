#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n;
int a[maxn];
int p[maxn];
int f[maxn];
long long ans;
int gcd(int a, int b) {return a % b == 0 ? b : gcd(b, a % b);}
void update(int x) {
    for (int i = 1; i <= n; i++) {
        if (p[i]) continue;
        f[i] = max(f[i], gcd(a[i], a[x]));
    }
}
int main() {
    freopen("gcd.in", "r", stdin);
    freopen("bf.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    p[1] = 1; update(1);
    for (int i = 1; i < n; i++) {
        int x = 0;
        for (int j = 1; j <= n; j++)
            if (!p[j] && f[j] > f[x]) x = j;
        ans += f[x]; p[x] = 1;
        update(x);
    }
    cout << ans << endl;
    cerr << clock() * 1. / 1000 << endl;
    return 0;
}