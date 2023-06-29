#include <iostream>

using namespace std;

int n;

int main() {
  cin >> n;
  if ((n - 1) % 4 == 0) {
    cout << 0;
    for (int i = 0; i < n / 4; i++) {
      cout << "0110";
    }
  } else {
    cout << -1;
  }
  cout << endl;
  return 0;
}