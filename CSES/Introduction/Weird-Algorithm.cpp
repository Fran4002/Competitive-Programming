#include <iostream>
using namespace std;

int main(){
  unsigned long long n;
  cin >> n;

  while (n != 1){
    cout << n << '\t';
    if (n % 2 == 0) n /= 2;
    else n = n * 3 + 1;
  }

  cout << 1;
}
