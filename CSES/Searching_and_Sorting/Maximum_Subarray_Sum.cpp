#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define all(x) x.begin(),x.end()
#define ll long long int

int main(){
  //cin.tie(null);  sync_with_stdio::(false);
  ll n, mss, lesser;

  cin >> n;

  vector <ll> presum(n + 1);

  cin >> presum[0];
  for (ll i = 1; i < n; i++) {
    cin >> presum[i];
    presum[i] += presum[i - 1];
  }
  mss = lesser = presum[0];

  for (ll i = 1; i < n; i++) {
    if (mss < presum[i] - lesser) {
      mss = presum[i] - lesser;
    }
    if (mss < presum[i]) {
      mss = presum[i];
    }
    if (lesser > presum[i]) {
      lesser = presum[i];
    }
  }

  cout << mss;

}
