#include <iostream>
using namespace std;

int main(){
  long long n, ans = 1;

  cin >> n;

  while (n){
    n--;
    ans *= 2;
    ans %= 1000000007;
  }

  cout << ans;
}
