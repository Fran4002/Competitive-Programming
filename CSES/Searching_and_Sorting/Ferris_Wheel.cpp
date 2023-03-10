#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define all(x) x.begin(),x.end()
#define ll long long int

int main(){
  ll n, x, total = 0;

  cin >> n >> x;

  vector <ll> kids(n);

  for (ll i = 0; i < n; i++) {
    cin >> kids[i];
  }

  sort(all(kids));

  for (ll i = 0, j = n - 1; i <= j; total++, j--) {
    if (kids[i] + kids[j] <= x)
      i++;
  }

  cout << total;

}
