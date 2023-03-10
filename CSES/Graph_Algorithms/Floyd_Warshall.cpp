#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define all(x) x.begin(),x.end()
#define INF 1e9

typedef long long int ll;
typedef vector<long long int> vi;

ll n, m;
vector <vi> d;

void entry();
void floyd_warshall ();

int main () {
  entry();
}

void entry()
{
  ll edg_e, edg_s, w;
  cin >> n;

  d.resize(n, vi(n, INF));

  for (ll i = 0; i < m; i++) {
    cin >> edg_e >> edg_s >> w;

    d[edg_e][edg_s] = d[edg_s][edg_e] = w;
  }
}

void floyd_warshall ()
{
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (d[i][k] < INF && d[k][j] < INF)
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
  }
}
