#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define all(x) x.begin(),x.end()

typedef long long int ll;
typedef vector<long long int> vi;

int main() {
  ll n, it = 2, rounds = 0;

  cin >> n;

  vi vec(n);

  for (ll i = 0; i < n; i++) {
    vec[i] = i + 1;
  }

  while (n) {
    if (it >= n) {
      rounds++;
      it %= n;
    }
    cout << it + rounds << " ";
    vec.erase(vec.begin() + it);
    n--;
    it += 2;
  }

}
