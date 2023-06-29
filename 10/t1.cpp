/*
 * @Author: hzw20071003 365424368@qq.com
 * @Date: 2022-10-23 09:49:40
 * @LastEditors: hzw20071003 365424368@qq.com
 * @LastEditTime: 2022-10-23 10:20:23
 * @FilePath: \workspace\10\t1.cpp
 * Copyright (c) 2022 by hzw20071003, All Rights Reserved.
 */
#include <iostream>

using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;
  for (; k > 0; k--) {
    n++;
    if (n % 3 == 0) {
      n /= 3;
    }
    if (n == 2 || n == 1) {
      cout << (long long)(n + k % 2) / ((n + k % 2) % 3 ? 1 : 3) << endl;
      return 0;
    }
  }
  cout << (long long)n << endl;
  return 0;
}