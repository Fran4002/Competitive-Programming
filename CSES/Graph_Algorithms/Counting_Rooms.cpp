#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

#define all(x) x.begin(),x.end()
#define ll long long int
#define vi vector<long long int>


int main(){
  ll n, m, rooms = 0;
  char c;
  queue <pair<ll,ll>> bfs;
  pair <ll, ll> coords;

  cin >> n >> m;

  vector<vi> visited(n,vi(m,1)), bmap(n,vi(m));

  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < m; ++j) {
      cin >> c;
      if (c == '#')
        bmap[i][j] = 0;
      else
        bmap[i][j] = 1;
    }
  }

  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < m; ++j) {
      if (bmap[i][j] && visited[i][j]) {
        bfs.push(make_pair(i, j));
        rooms++;
      }
      while (!bfs.empty()){
        coords = bfs.front();
        bfs.pop();
        if (coords.first > 0) {
          if (visited[coords.first - 1][coords.second] && bmap[coords.first - 1][coords.second]) {
            visited[coords.first - 1][coords.second] = 0;
            bfs.push(make_pair(coords.first - 1, coords.second));
          }
        }
        if (coords.first < n - 1) {
          if (visited[coords.first + 1][coords.second] && bmap[coords.first + 1][coords.second]) {
            visited[coords.first + 1][coords.second] = 0;
            bfs.push(make_pair(coords.first + 1, coords.second));
          }
        }
        if (coords.second > 0) {
          if (visited[coords.first][coords.second - 1] && bmap[coords.first][coords.second - 1]) {
            visited[coords.first][coords.second - 1] = 0;
            bfs.push(make_pair(coords.first, coords.second - 1));
          }
        }
        if (coords.second < m - 1) {
          if (visited[coords.first][coords.second + 1] && bmap[coords.first][coords.second + 1]) {
            visited[coords.first][coords.second + 1] = 0;
            bfs.push(make_pair(coords.first, coords.second + 1));
          }
        }
      }
    }
  }

  cout << rooms;

}
