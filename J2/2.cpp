/*
 * @Author: hzw20071003 365424368@qq.com
 * @Date: 2022-10-16 09:09:10
 * @LastEditors: hzw20071003 365424368@qq.com
 * @LastEditTime: 2022-10-16 09:38:20
 * @FilePath: \workspace\J2\2.cpp
 * Copyright (c) 2022 by hzw20071003, All Rights Reserved.
 */
#include <iostream>
#include <queue>

using namespace std;

long long n, a, b, c, ans, opt, z[2];
priority_queue<pair<long long, long long>> Max[1001][1001];
pair<long long, long long> tmp;

int main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a >> b >> c;
    Max[a][b].push({c, i});
    Max[a][c].push({b, i});
    Max[b][a].push({c, i});
    Max[b][c].push({a, i});
    Max[c][a].push({b, i});
    Max[c][b].push({a, i});
  }
  for (long long i = 1000; i >= ans; i--) {
    for (long long j = 1000; j >= ans; j--) {
      if (Max[i][j].empty()) {
        continue;
      }
      tmp = Max[i][j].top();
      while (!Max[i][j].empty() && Max[i][j].top().second == tmp.second) {
        Max[i][j].pop();
      }
      if (!Max[i][j].empty()) {
        long long k = min(min(i, j), tmp.first + Max[i][j].top().first);
        if (k > ans) {
          opt = 1;
          z[0] = tmp.second, z[1] = Max[i][j].top().second;
          if (z[0] > z[1]) {
            swap(z[0], z[1]);
          }
          ans = k;
        }
      } else {
        long long k = min(min(i, j), tmp.first);
        if (k > ans) {
          opt = 0;
          z[0] = tmp.second;
          ans = k;
        }
      }
    }
  }
  cout << opt << endl;
  for (long long i = 0; i <= opt; i++) {
    cout << z[i] << ' ';
  }
  cout << endl;
  cout << ans * ans * ans / 4;
  return 0;
}