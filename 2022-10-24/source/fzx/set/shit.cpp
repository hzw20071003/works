#define fastcall __attribute__((optimize("-O3")))
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

unsigned int c[6], lg[35];
vector<unsigned int> l;

unsigned int popcount(unsigned int x) {
  unsigned int _c = 0;
  for (unsigned int i = 0; i <= 20; ++i) {
    _c += x >> i & 1;
  }
  return _c;
}

int main() {
  freopen("shit.out", "w", stdout);
  for (int i = 0; i <= 5; ++i) {
    lg[1 << i] = i;
  }
  for (int _ = 1; _ <= 5; ++_) {
    unsigned int n = (1 << _) - 1;
    fill_n(c, 5, 0), l.clear();
    for (unsigned int i = 1; i <= (1ull << n + 1) - 1; ++i) {
      bool f = 1;
      for (unsigned int j = 0; f && j <= n; ++j) {
        for (unsigned int k = 0; f && k <= n; ++k) {
          if ((i >> j & 1) && (i >> k & 1) &&
              (!(i >> (j ^ k) & 1) || (j ^ k) > n)) {
            f = 0;
          }
        }
      }
      if (f) {
        ++c[lg[popcount(i)]];
        // l.push_back(i);
      }
    }
    // cout << c[0] + c[1] + c[2] + c[3] + c[4] << ' ';
    cout << "n=" << n << '\n';
    cout << "c=" << c[0] << ' ' << c[1] << ' ' << c[2] << ' ' << c[3] << ' ' << c[4] << ' ' << c[5] << '\n';
    // sort(l.begin(), l.end(), [&](const auto &i, const auto &j) -> bool {
    //   if (popcount(i) != popcount(j)) {
    //     return popcount(i) < popcount(j);
    //   }
    //   for (unsigned int k = 0; k <= n; ++k) {
    //     if ((i >> k & 1) ^ (j >> k & 1)) {
    //       return (i >> k & 1) > (j >> k & 1);
    //     }
    //   }
    //   return 0;
    //   // return popcount(i) < popcount(j) || popcount(i) == popcount(j) && i < j;
    // });
    // for (auto &i : l) {
    //   for (unsigned int j = 0; j <= n; ++j) {
    //     cout << ((i >> j & 1) ? '1' : ' ');
    //   }
    //   cout << '\n';
    // }
    // cout << "====================================\n";
  }
  return 0;
}