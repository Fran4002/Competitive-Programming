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
  vll h, s, dp;

  cin >> n >> x;
  h.resize(n);
  s.resize(n);
  readv(h);
  readv(s);

  dp.resize(x + 1, 0);

  ll ans = 0;

  for (ll i = 0; i < n; i++) {
    for (ll j = x; j >= h[i]; j--) {
      dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
      ans = max(dp[j], ans);
    }
  }

  cout << ans << '\n';
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
