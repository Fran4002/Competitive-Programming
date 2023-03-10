#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define all(x) x.begin(),x.end()
#define ll long long int

int main(){
  ll n, x, objective = 0;

  cin >> n >> x;

  vector <ll> presum(n + 1);

  presum[0] = 0;
  for (ll i = 1; i <= n; i++) {
    cin >> presum[i];
    presum[i] += presum[i - 1];
  }

  for (ll i = 1, j = 0; i <= n && j <= n;) {
    //cout << i << " " << j << " ";
    if (presum[i] - presum[j] == x) {
      objective++;
      i++;
      //cout << "= x\n";
    }
    else if (presum[i] - presum[j] < x) {
      i++;
      //cout << "< x\n";
    }
    else {
      j++;
      //cout << "> x\n";
    }
  }

  cout << objective;
}
