#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
bool p[25];
int main() {
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
    cin >> n;
    for (int i = 1; i < (1 << n + 1); i++) {
        memset(p, 0, sizeof(p));
        for (int j = 0; j <= n; j++)
            if ((i >> j) & 1) p[j] = 1;
        int fl = 0;
        for (int j = 1; j <= n && fl == 0; j++)
            for (int k = 1; k <= j; k++) {
                if (!p[j] || !p[k]) continue;
                int x = (j ^ k);
                if (x > n || !p[x]) {fl = 1; break;}
            }
        ans += !fl;
    }
    cout << ans << endl;
    return 0;
}