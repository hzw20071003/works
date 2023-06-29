/*
 * @Author: hzw20071003 365424368@qq.com
 * @Date: 2022-10-13 11:39:47
 * @LastEditors: hzw20071003 365424368@qq.com
 * @LastEditTime: 2022-10-13 15:27:18
 * @FilePath: \workspace\P2398\P2398.cpp
 * Copyright (c) 2022 by hzw20071003, All Rights Reserved.
 */
#include <iostream>

using namespace std;

int n;
long long ans;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    // cout << max(((n / i) * 2 - 1), 1) * i << ' ' << n - i - n / i + 1 << endl;
    ans += max(((n / i) * 2 - 1), 1) * i;
    ans += max((n / i - 2) * 2, 0) * i;
    ans += (n - i - n / i + 1) * 2;
  }
  cout << ans;
  return 0;
}