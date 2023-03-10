#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define all(x) x.begin(),x.end()

typedef long long int ll;
typedef vector<long long int> vi;
typedef vector<pair<long long int, long long int>> pii;

struct nsv {
  vi values, parent;

  nsv (ll n) {
    parent.resize(n);
    values.resize(n);

    for (ll i = 0; i < n; ++i){
      cin >> values[i];
      parent[i] = 0;
    }

    parent[0] = -1;
  }

  ll find (ll u, ll v){
    if (parent[u] == 0) {
      if (v < 0) parent[u] = -1;
      else if (values[u] > values[v]) parent[u] = v;
      else parent[u] = find(u, parent[v]);
    }

    return parent[u];
  }
};

int main() {
  ll n, x;

  cin >> n;

  nsv vec(n);

  for (ll i = 0; i < n; ++i) {
    cout << vec.find(i, i - 1) + 1<< " ";
  }
}
