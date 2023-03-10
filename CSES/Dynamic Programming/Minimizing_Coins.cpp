#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//const int small_dice[6] = {1, 1, 4, }
vector<long long> steps(1000000,0);

int main(){
  long long n, x;

  cin >> n >> x;

  std::vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    steps[v[i]] = 1;
  }

  sort(v.begin(), v.end());

  for (long long i = v[0]; i <= x; i++) {
    if (steps[i]){
      for (long long j = 0; j < n; j++) {
          if (i + v[j] > x){
            break;
          }
          else if (steps[i + v[j]] == 0)
            steps[i + v[j]] = steps[i] + 1;
          else
            steps[i + v[j]] = min(steps[i] + 1, steps[i + v[j]]);
      }
    }
  }
  if (steps[x])
    cout << steps[x];
  else
   cout << -1;
}

//+52 1 444 867 0528
