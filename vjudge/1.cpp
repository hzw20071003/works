/*
 * @Author: hzw20071003 365424368@qq.com
 * @Date: 2023-06-27 22:11:01
 * @LastEditors: hzw20071003 365424368@qq.com
 * @LastEditTime: 2023-06-29 12:51:59
 * @FilePath: \workspace\vjudge\1.cpp
 * Copyright (c) 2023 by hezewei, All Rights Reserved.
 */
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int kMaxN = 201, kMaxM = 2001;

struct line {
  int x, y, v, f;
  line Add(int x, int y, int v, int f) {
    line tmp;
    tmp.x = x, tmp.y = y, tmp.v = v, tmp.f = f;
    return tmp;
  }
};

struct dot {
  int h;
  vector<int> l;
  void Reset() {
    l.clear();
    h = 0;
  }
};

void Add_line(int x, int y, int v, int f) {
  dot[x].l.push_back(l.size());
  l.push_back(Add(x, y, v, f));
  dot[y].v.push_back(l.size());
  l.push_back(Add(y, x, v, 0));
}

bool Deep(int s, int t;) {
  queue<int> q;
  q.push(s);
  dot[s].h = 1;
  while (!q.empty()) {
    int tmp = q.top();
    q.pop();
    for (int i = 0; i < dot[tmp].l; i++) {
      if (dot[dot[tmp][i]].h == 0) {
        q.push(dot[tmp][i]);
        dot[dot[tmp][i]].h = dot[tmp].h + 1;
      }
    }
  }
  return dot[t].h > 0;
}

int Find(int x) {
}

vector<line> l;
vector<dot> dot[kMaxN];
int n, m, s, t, u, v, w, ans;

int main() {
  cin >> n >> m >> s >> t;
  while (m--) {
    cin >> u >> v >> w;
    Add_line(u, v, 0, w);
  }
  while (Deep(s, t)) {
    ans += Find(s, 10001);
  }
  cout << ans << endl;
  return 0;
}