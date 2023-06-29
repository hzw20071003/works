/*
 * @Author: hzw20071003 365424368@qq.com
 * @Date: 2022-10-23 10:41:29
 * @LastEditors: hzw20071003 365424368@qq.com
 * @LastEditTime: 2022-10-23 11:55:32
 * @FilePath: \workspace\10\t3.cpp
 * Copyright (c) 2022 by hzw20071003, All Rights Reserved.
 */
#include <cmath>
#include <iostream>

using namespace std;

long long ans;
long long n, k, a, tmp[10000001], num[10000001];
const long long kMaxN = 998244353;

long long read() {
  long long x(0), f(1);
  char ch(getchar());
  while (ch < '0' || '9' < ch) {
    if (ch == '-') {
      f = -1;
    }
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch - '0');
    ch = getchar();
  }
  return f * x;
}

int main() {
  // freopen("ex.in", "r", stdin);
  // freopen("ex.ans", "w", stdout);
  n = read(), k = read();
  for (long long i = 1; i <= k; i++) {
    num[i] = ((i * i) % kMaxN + num[i - 1]) % kMaxN;
    tmp[i] = (i + tmp[i - 1]) % kMaxN;
  }
  while (n--) {
    a = read();
    if (a >= 0) {
      ans += ((long long)pow(a, 2) * k) % kMaxN + num[k] + (a * tmp[k] * 2) % kMaxN;
      ans %= kMaxN;
    } else {
      a += 1;
      ans += ((long long)pow(a, 2) % kMaxN) * (k + a * 2 > 0 ? -a * 2 : k) % kMaxN;
      ans %= kMaxN;
      if (k + a * 2 > 0) {
        ans += (((a - 1) % kMaxN * (a - 1) % kMaxN * (k + a * 2) % kMaxN) % kMaxN + num[k] - num[-a * 2] + ((a - 1) * (tmp[k] - tmp[-a * 2]) * 2) % kMaxN) % kMaxN;
        ans %= kMaxN;
      }
    }
  }
  cout << ans << endl;
  return 0;
}