#include <iostream>
using namespace std;

/*
Given a number n
Find the number of trailing zeros of n!
*/

int main(){
  long long n, ans = 0;

  cin >> n;

  while (n){
    n /= 5;
    ans += n;
  }

  cout << ans;
}
