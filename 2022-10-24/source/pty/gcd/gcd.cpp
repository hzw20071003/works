#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("gcd.in");
ofstream fout("gcd.out");

const int kMaxN = 1e5 + 1;

int r[kMaxN], n, m;
long long ans;

int R(int x) { return r[x] == x ? x : r[x] = R(r[x]); }

int main() {
  fin >> n;
  for (int i = 1, x; i <= n; i++) {
    fin >> x;
    if (r[x]) {  // 重复值
      ans += x;  // 直接连边并去重
    } else {     // 新值
      r[x] = x;  // 初始化并查集
    }
    m = max(m, x);  // 更新最大值
  }
  for (int i = m, j; i >= 1; i--) {         // 枚举公约数
    for (j = i; j <= m && !r[j]; j += i) {  // 找到第一个存在的点
    }
    for (int k = j; k <= m; k += i) {  // 枚举其他点
      if (r[k] && R(k) != R(j)) {      // 存在尚未连通的点
        ans += i;                      // 累加答案
        r[R(k)] = R(j);                // 连接
      }
    }
  }
  fout << ans;
  return 0;
}