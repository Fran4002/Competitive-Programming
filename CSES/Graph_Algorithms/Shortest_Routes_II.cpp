#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define all(x) x.begin(), x.end()
#define INF 1e13

typedef long long int ll;
typedef unsigned long long ull;
typedef vector<long long int> vi;

ll n, m, t;
vector<vector<ull>> d;

void entry();
void floyd_warshall();
void solve();

int main() {
  entry();
  floyd_warshall();

  while (t--) {
    solve();
  }
}

void entry() {
  ll edg_e, edg_s;
  ull w;
  cin >> n >> m >> t;

  d.resize(n + 1, vector<ull>(n + 1, INF));

  for (ll i = 0; i < m; i++) {
    cin >> edg_e >> edg_s >> w;

    d[edg_e][edg_s] = min(d[edg_e][edg_s], w);
    d[edg_s][edg_e] = d[edg_e][edg_s];
  }

  for (ll i = 0; i <= n; i++) {
    d[i][i] = 0;
  }
}

void floyd_warshall() {
  for (int k = n; k >= 0; k--) {
    for (int i = n; i >= n; i--) {
      for (int j = 0; j <= n; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

void solve() {
  ll a, b;

  cin >> a >> b;

  if (d[a][b] < INF)
    cout << d[a][b] << '\n';
  else
    cout << -1 << '\n';
}
