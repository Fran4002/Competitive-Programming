#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(),x.end()
#define readv(x) for (auto &v: x) cin >> v;
#define printv(x) for (auto &v: x) cout << v << " ";

using ll = long long int;
using ull = unsigned long long int;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vc = vector<char>;

void solve () {
  ll n;
  vll arr;

  cin >> n;
  arr.resize(n);
  readv(arr);

  vll lis;

  for (const ll &x: arr) {
    vll::iterator it = lower_bound(all(lis), x);

    if (it == lis.end()) lis.push_back(x);
    else *it = x;
  }

  cout << lis.size() << '\n';
}

int main () {
  //cin.tie(0) -> ios_base::sync_with_stdio(0);

  int t = 1;

  //cin >> t;

  for (int i = 1; i <= t; i++) {
    //cout << "Test #" << i << ":\n";
    solve();
  }
}
