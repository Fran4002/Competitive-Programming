#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//const int small_dice[6] = {1, 1, 4, }
vector<long long> v(1000000,0);

long long dice(long long n){
  if (n < 0)
    return 0;
  else if (n == 0)
    return 1;
  else
    if (v[n] == 0)
      v[n] = (dice(n-1) + dice(n-2) + dice(n-3) + dice(n-4) + dice(n-5) + dice(n-6)) % 1000000007;
    return v[n];

}


int main(){
  long long n;

  cin >> n;

  cout << dice(n);
}
