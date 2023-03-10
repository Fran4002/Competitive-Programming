#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define all(x) x.begin(),x.end()

typedef long long int ll;
typedef vector<long long int> vi;

ll n, total = 0, mindif;
vi apples;

/*ll abs(ll n) {
  if (n < 0) return -n;
  else return n;
}*/

ll dp(ll i, ll w) {
  ll with, without;

  if (i < n) {
    with = dp(i + 1, w + apples[i]);
    without = dp(i + 1, w);

    cout << "indice: " << i << " - con es: " << with << " - sin es: " << without << '\n';

    return min(with, without);
  }
  else
    return w;
}

int main() {
  cin >> n;

  apples.assign(n, 0);

  for (ll i = 0; i < n; i++) {
    cin >> apples[i];
    total += apples[i];
  }

  mindif = total;
  mindif = dp(0, 0);

  cout << mindif;
}
