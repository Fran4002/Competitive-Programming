#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(),x.end()
#define readv(x) for (auto &v: x) cin >> x;
#define printv(x) for (auto &v: x) cout << x;

using ll = long long int;
using ull = unsigned long long int;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vc = vector<char>;

const ll MOD = 1e9 + 7;

void solve () {
  ll n;
  vll dp;

  cin >> n;
  dp.resize(n + 1);

  for (ll i = min(6ll, n); i > 0; i--) dp[i] = 1;

  for (ll i = 1; i < n; i++) {
    for (ll j = 1; j <= 6; j++) {
      if (i + j > n) break;
      dp[i + j] += dp[i];
      dp[i + j] %= MOD;
    }
  }

  cout << dp[n] << '\n';
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
