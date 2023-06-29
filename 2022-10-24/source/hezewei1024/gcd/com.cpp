#include <iostream>
#include <windows.h>
#include <random>
#include <ctime>

using namespace std;

int main() {
  while(1) {
    system("build.exe");
    auto t = clock();
    system("gcd.exe");
    cout << "gcd:" << clock() - t << endl;
    t = clock();
    system("hack.exe");
    cout << "hack:" << clock() - t << endl;
    if(system("fc 1.out gcd.out")) {
      return 0;
    }
  }
}