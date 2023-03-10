#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//const int small_dice[6] = {1, 1, 4, }

int main(){
  long long n, x;

  cin >> n >> x;

  vector<long long> steps(1000000,0);
  std::vector<long long> coins(n);

  for (long long i = 0; i < n; i++) {
    cin >> coins[i];
    steps[coins[i]] = 1;
  }

  sort(coins.begin(), coins.end());

  for (long long i = coins[0]; i <= x; i++) {
    if (steps[i]){
      for (long long j = 0; j < n; j++) {
          if (i + coins[j] > x){
            break;
          }
          else
            steps[i + coins[j]] = (steps[i + coins[j]] + steps[i]) % 1000000007;
      }
    }
  }

  cout << steps[x];
}

//+52 1 444 867 0528
