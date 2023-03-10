#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

#define all(x) x.begin(), x.end()
#define ll long long int
#define vi vector<long long int>

int main() {
  ll n, m, e, s;
  queue<ll> bfs;
  bool possible = false;

  cin >> n >> m;

  vi visited(n, 0), path(n), f_path;
  vector<vi> roads(n, vi());

  for (ll i = 0; i < m; ++i) {
    cin >> e >> s;
    roads[e - 1].push_back(s - 1);
    roads[s - 1].push_back(e - 1);
  }

  bfs.push(0);

  while (!bfs.empty()) {
    e = bfs.front();
    bfs.pop();

    if (e == n - 1) {
      possible = true;
      break;
    }

    for (ll j = 0; j < roads[e].size(); ++j) {
      if (visited[roads[e][j]] == 0) {
        bfs.push(roads[e][j]);
        visited[roads[e][j]] = 1;
        path[roads[e][j]] = e;
      }
    }
  }

  if (possible) {
    while (e != 0) {
      f_path.push_back(e);
      e = path[e];
    }
    reverse(all(f_path));
    cout << f_path.size() + 1 << '\n' << 1;
    for (ll i = 0; i < f_path.size(); ++i) {
      cout << " " << f_path[i] + 1;
    }
  } else
    cout << "IMPOSSIBLE";
}
