#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define all(x) x.begin(),x.end()

typedef long long int ll;
typedef vector<long long int> vi;

int main() {
  ll n, div = 0;

  cin >> n;

  vi presum (n, 0), equal (n, 0);

  cin >> presum[0];
  presum[0] %= n;
  equal[presum[0]]++;

  for (ll i = 1; i < n; i++) {
    cin >> presum[i];
    while (presum[i] < 0) presum[i] += n;
    presum[i] = (presum[i] + presum[i - 1]) % n;
    equal[presum[i]]++;
  }

  div += (equal[0] * (equal[0] + 1)) / 2;
  for (ll i = 1; i < n; i++) {
    div += (equal[i] * (equal[i] - 1)) / 2;
  }

  cout << div;
}
