/*
 * @Author: hzw20071003 365424368@qq.com
 * @Date: 2022-11-06 10:02:55
 * @LastEditors: hzw20071003 365424368@qq.com
 * @LastEditTime: 2022-11-06 10:18:33
 * @FilePath: \workspace\1106\test.cpp
 * Copyright (c) 2022 by hzw20071003, All Rights Reserved.
 */
#include <iostream>
#include <map>

using namespace std;

int n, a, ans, Last[10001];
map<int, int> m;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    s.insert(a);
    cout << *s.find(a);
  }
  return 0;
}