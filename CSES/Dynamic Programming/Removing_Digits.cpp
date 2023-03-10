#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//const int small_dice[6] = {1, 1, 4, }
long long GreaterDigit(long long n){
  long long d = 0;
  while (n){
    if(n % 10 > d) d = n % 10;
    n /= 10;
  }
  return d;
}

int main(){
  long long n, steps = 0;

  cin >> n;

  //std::vector<long long> digits = QoD(n);

  while (n){
    n -= GreaterDigit(n);
    steps++;
  }

  cout << steps;
}
