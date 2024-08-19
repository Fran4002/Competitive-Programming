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
  ll n, x;
  vll dp, coins;

  cin >> n >> x;
  coins.resize(n);
  dp.resize(x + 1, 1e9);
  readv(coins);

  dp[0] = 0;
  for (ll c: coins) {
    for (ll i = c; i <= x; i++) {
      dp[i] = min(dp[i], dp[i - c] + 1);
    }
  }

  cout << (dp[x] == 1e9? -1: dp[x]) << '\n';
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
