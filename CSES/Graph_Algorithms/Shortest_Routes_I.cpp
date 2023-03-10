#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

#define all(x) x.begin(), x.end()
typedef long long int ll;
typedef vector<long long int> vi;

bool sortpair (const pair<ll, ll> &a, const pair<ll,ll> &b) {
  if (a.first == b.first)
    return (a.second < b.second);
  else
    return (a.first < b.first);
}

int main() {
  ll n, m, origen, destino, costo;
  pair<ll, ll> actual;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll,ll>>> bfs;
  //vector <pair<ll, ll>> bfs;

  cin >> n >> m;

  vi visited(n, 0), c_path(n, 0), fixed(n, 0);
  vector<vector<pair<ll, ll>>> edges(n, vector<pair<ll, ll>>());

  for (ll i = 0; i < m; ++i) {
    cin >> origen >> destino >> costo;
    edges[origen - 1].push_back(make_pair(destino - 1, costo));
  }

  bfs.push(make_pair(0, 0));
  visited[0] = 1;

  while (!bfs.empty()) {
    actual = bfs.top();    bfs.pop();

    if (fixed[actual.second] == 0)
      fixed[actual.second] = 1;
    else
      continue;

    for (ll i = 0; i < edges[actual.second].size(); i++) {
      //Si no ha sido visitado o si el camino es mas corto
      if (visited[edges[actual.second][i].first] == 0 ||
          actual.first + edges[actual.second][i].second < c_path[edges[actual.second][i].first]) {
        visited[edges[actual.second][i].first] = 1;
        c_path[edges[actual.second][i].first] = actual.first + edges[actual.second][i].second;
        bfs.push(make_pair(actual.first + edges[actual.second][i].second, edges[actual.second][i].first));
      }
    }
  }

  for (ll i = 0; i < n; ++i) {
    cout << c_path[i] << " ";
  }
}
