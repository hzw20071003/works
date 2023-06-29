/*
 * @Author: hzw20071003 365424368@qq.com
 * @Date: 2022-11-05 09:17:43
 * @LastEditors: hzw20071003 365424368@qq.com
 * @LastEditTime: 2022-11-05 10:16:37
 * @FilePath: \workspace\1105\hack.cpp
 * Copyright (c) 2022 by hzw20071003, All Rights Reserved.
 */
#include <iostream>
using namespace std;
int main() {
  freopen("ikun.in", "w", stdout);
  cout << 1000 << endl;
  for (int i = 1000 * (1000 + 1); i >= 1; i--) {
    cout << i << ' ';
  }
  cout << endl;
}