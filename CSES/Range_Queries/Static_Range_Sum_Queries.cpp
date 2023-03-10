#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define all(x) x.begin(),x.end()
#define ll long long int

int main(){
  ll n, q, r1, r2;

  cin >> n >> q;

  vector <ll> presum(n + 1);

  presum[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> presum[i];
    presum[i] += presum[i - 1];
  }

  for (int i = 0; i < q; i++) {
    cin >> r1 >> r2;

    cout << presum[r2] - presum[r1 - 1] << '\n';
  }

}
