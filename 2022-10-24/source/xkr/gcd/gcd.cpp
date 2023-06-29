#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n;
int a[maxn];
int p[maxn];//位置i是否有数
int f[maxn];//每个数最大gcd
int vis[maxn];//i是否作为因数被更新过
int h[maxn];
vector<int> d[maxn];//i的所有因数
long long ans, cnt;
struct node {
    int id, dis;
    bool operator < (const node &a) const {return dis < a.dis;}
};
priority_queue<node> q;
void init() {
    for (int i = 1; i <= 100000; i++)
        for (int j = i; j <= 100000; j += i)
            d[j].push_back(i);
}
void update(int x) {
    if (h[x]) return;
    h[x] = 1;
    cnt++;
    for (int i = d[x].size() - 1; i >= 0; i--) {
        int k = d[x][i];
        if (vis[k]) continue; vis[k] = 1;
        for (int j = k; j <= 100000; j += k) {
            if (!p[j]) continue;
            if (f[j] < k) {
                f[j] = k;
                for (int s = 1; s <= p[j]; s++) q.push((node){j, f[j]});
            }
        }
    }
}
int main() {
    freopen("gcd.in", "r", stdin);
    freopen("gcd.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        p[a[i]]++;
    }
    init();
    update(a[1]); p[a[1]]--;
    while (!q.empty()) {
        node cur = q.top(); q.pop();
        int u = cur.id;
        // cerr << u << endl;
        if (!p[u]) continue; p[u]--;
        ans += cur.dis; update(u);
    }
    cout << ans << endl;
    // cerr << clock() * 1. / 1000 << endl;
    // cerr << cnt << endl;
    return 0;
}