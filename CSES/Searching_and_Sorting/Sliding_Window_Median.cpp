#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(x) x.begin(), x.end()
#define readv(x) for (auto &v : x) cin >> v;
#define printv(x) for (auto &v : x) cout << v << " ";
#define readp(p) cin >> p.first >> p.second;

using ll = long long int;
using ull = unsigned long long int;
using vi = vector<int>;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vc = vector<char>;

template<typename T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


const ll INF = 1e9;
const ll MOD = 1e9 + 7;

inline ll gauss(ll n) { return n * (n + 1) / 2;}

void solve() {
  ll n, k;
  ordered_set<ll> oSet;

  cin >> n >> k;
  vll arr(n);
  readv(arr);

  for (ll i = 0; i < k; i++) {
    oSet.insert(arr[i]);
  }

  cout << *oSet.find_by_order((k - 1)  / 2) << ' ';

  for (ll i = k; i < n; i++) {
    auto it = oSet.lower_bound(arr[i - k] - 1);
    ll num = *it;
    oSet.erase(it);
    oSet.insert(arr[i]);
    
    cout << *oSet.find_by_order((k - 1) / 2) << ' ';
  }

  cout << '\n';
}

int main() {
  //cin.tie(0)->ios_base::sync_with_stdio(0);

  ll t = 1;

  //cin >> t;

  for (ll i = 1; i <= t; i++) {
    //cout << "Test #" << i << ":\n";
    solve();
  }
}