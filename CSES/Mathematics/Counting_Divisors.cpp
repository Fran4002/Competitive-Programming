#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

#define ll long long int

void solve() {
  ll n, sq, num_div = 1;
  vector <ll> div;

  cin >> n;

  if (n % 2 == 0) {
    div.push_back(0);
    while (n % 2 == 0) {
      div.back()++; n /= 2;
    }
  }

  for (ll i = 3; n > 1; i += 2) {
    if (n % i == 0) {
      div.push_back(0);

      while (n % i == 0) {
        div.back()++;
        n /= i;
      }
    }
  }

  if (!div.empty())
    while (!div.empty()){
      num_div *= div.back() + 1;
      div.pop_back();
    }

  cout << num_div << '\n';
}

int main() {
  ll t;

  cin >> t;

  while (t--) {
    solve();
  }
}
