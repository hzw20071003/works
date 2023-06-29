#include <ctime>
#include <iostream>

using namespace std;

const int kMaxN = 100000, kMaxV = 100000;

int main() {
  freopen("gcd.in", "w", stdout);
  srand(time(0));
  cout << kMaxN << '\n';
  for (int i = 1; i <= kMaxN; i++) {
    cout << rand() * rand() % kMaxV + 1 << ' ';
  }
  return 0;
}
