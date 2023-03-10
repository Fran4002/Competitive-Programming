#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef signed long long int ll;
typedef vector<signed long long int> vi;

int main() {
  ll n, x, total = 0;

  cin >> n >> x;

  vi coins(n);
  vector<vector<ll>> steps(100000005, vi(n, 0));

  for (ll i = 0; i < n; i++) {
    cin >> coins[i];
  }

  sort(coins.begin(), coins.end());

  for (ll i = 0; i < n; i++) {
    steps[coins[i]][i] = 1;
  }

  for (ll i = coins[0]; i < x; i++) {
    for (ll j = 0; j < n; j++) {
      if (steps[i][j]) {
        for (ll g = j; g < n; g++) {
          if (i + coins[g] > x)
            break;
          else
            steps[i + coins[g]][g] = (steps[i + coins[g]][g] + 1) % 1000000007;
        }
      }
    }
  }

  for (ll i = 0; i < n; i++) {
    total += steps[x][i];
    total %= 1000000007;
  }

  cout << total;
}
