/*
 * @Author: hzw20071003 365424368@qq.com
 * @Date: 2022-10-13 14:27:34
 * @LastEditors: hzw20071003 365424368@qq.com
 * @LastEditTime: 2022-10-13 14:27:37
 * @FilePath: \workspace\P2398\compare.cpp
 * Copyright (c) 2022 by hzw20071003, All Rights Reserved.
 */
#include <cstdio>
#define re register int
long long n, ans, f[100010];
int main() {
  scanf("%lld", &n);
  for (re i = n; i; --i) {
    f[i] = n / i * (n / i);
    for (re j = i << 1; j <= n; j += i) f[i] -= f[j];
    ans += f[i] * i;
  }
  printf("%lld", ans);
  return 0;
}