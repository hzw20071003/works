/*
 * @Author: hzw20071003 365424368@qq.com
 * @Date: 2022-10-24 19:45:07
 * @LastEditors: hzw20071003 365424368@qq.com
 * @LastEditTime: 2022-10-24 21:47:17
 * @FilePath: \workspace\2022-10-24\source\hezewei1024\set\compare.cpp
 * Copyright (c) 2022 by hzw20071003, All Rights Reserved.
 */
#include <iostream>

using namespace std;

const long long kMaxN = 32, kMod = 1e9 + 7;
long long n, ans, f[kMaxN][kMaxN][2];

int main() {
  cin >> n;
  f[30][0][1] = 1;
  for (long long i = 29; i >= 0; i--) {
    for (long long j = 0, x = 1, y = 0; j <= 30; x = y = (1 << j), j++) {
      f[i][j][0] = (f[i][j][0] + (1ll << j) * f[i + 1][j][0]) % kMod;
      f[i][j + 1][0] = (f[i][j + 1][0] + f[i + 1][j][0]) % kMod;
      if (n >> i & 1) {
        f[i][j][0] = (f[i][j][0] + x * f[i + 1][j][1]) % kMod;
        f[i][j][1] = (f[i][j][1] + y * f[i + 1][j][1]) % kMod;
        f[i][j + 1][1] = (f[i][j + 1][1] + f[i + 1][j][1]) % kMod;
      } else {
        f[i][j][1] = (f[i][j][1] + x * f[i + 1][j][1]) % kMod;
      }
    }
  }
  for (int i = 0; i <= 30; i++) {
    ans = (ans + f[0][i][0] + f[0][i][1]) % kMod;
  }
  cout << ans;
  return 0;
}
