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

ll fast_exp (ll n, ll a) {
  if (a == 0) return 1;

  ll res = fast_exp(n, a / 2);
  res = (res * res) % MOD;

  if (a % 2) {
    res = res * n % MOD;
  }

  return res;
}

void solve () {
  ll n;
  vll dp;

  cin >> n;

  ll obj = n * (n + 1) / 2;

  if (obj % 2) {
    cout << 0 << '\n';
    return;
  }
  obj >>= 1;

  dp.resize(obj + 1, 0);
  dp[0] = 1;

  for (ll i = 1; i <= n; i++) {
    for (ll j = obj; j > i; j--) {
      dp[j] += dp[j - i];
      dp[j] %= MOD;
    }
    dp[i]++;
  }

  cout << dp.back() * fast_exp(2, MOD - 2) % MOD << '\n';
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
