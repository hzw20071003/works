#include <windows.h>

#include <iostream>

using namespace std;

int main() {
  for (long long i = 1; ; i++) {
    cout << "[" << i << "]\n";
    system("start /b sample.exe");
    system("start /b gcd2.exe");
    system("start /b gcd.exe");
    Sleep(350);
    if (system("fc gcd.out gcd.ans")) {
      break;
    }
  }
  return 0;
}
