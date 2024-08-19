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

const ll MOD = 1e9 + 7;

void solve () {
  ll n, x;
  vll dp;
  set<ll> coins;

  cin >> n >> x;
  dp.resize(x + 1, 0);

  for (ll i = 0; i < n; i++) {
    ll c;
    cin >> c;

    coins.insert(c);
  }

  dp[0] = 1;
  for (ll i = 0; i < x; i++) {
    for (ll c: coins) {
      if (c + i > x) break;
      dp[c + i] += dp[i];
      dp[c + i] %= MOD;
    }
  }

  cout << dp[x] << '\n';
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
