#include <ctime>
#include <iostream>
#include <random>

using namespace std;

int main() {
  srand(time(0));
  freopen("gcd.in", "w", stdout);
  int n = (rand() % 100000) + 1;
  cout << n << endl;
  for (int i = 0; i < n; i++) {
    cout << (rand() % 100000) + 1 << ' ';
  }
  return 0;
}