#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

#define all(x) x.begin(),x.end()
#define ll long long int
#define vi vector<long long int>

int main() {
  cin.tie(nullptr) -> sync_with_stdio(false);
  queue<pair<ll,ll>> bfs;
  pair <ll, ll> entry, exit, current;
  vector <char> fpath;
  ll n, m;
  char c;
  bool possible = false;

  cin >> n >> m;

  vector <vi> visited(n,vi(m,0));
  vector <vector<char>> path(n,vector<char>(m));

  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < m; ++j) {
      cin >> c;
      if (c == 'A') {
        visited[i][j] = 1;
        entry = make_pair(i, j);
        bfs.push(entry);
      }
      else if (c == 'B')
        exit.first = i, exit.second = j;
      else if (c == '#')
        visited[i][j] = 1;
    }
  }

  while(!bfs.empty()){
    current = bfs.front(); bfs.pop();

    //cout << current.path << " " << current.first << " " << current.second << '\n';

    if (current == exit){
      possible = true;
      break;
    }
    if (current.first > 0) {
      if (visited[current.first - 1][current.second] == 0) {
      //  cout << "U ";
        visited[current.first - 1][current.second] = 1;
        path[current.first - 1][current.second] = 'U';
        bfs.push(make_pair(current.first - 1, current.second));
      }
    }
    if (current.first < n - 1) {
      if (visited[current.first + 1][current.second] == 0) {
        //cout << "D ";
        visited[current.first + 1][current.second] = 1;
        path[current.first + 1][current.second] = 'D';
        bfs.push(make_pair(current.first + 1, current.second));
      }
    }
    if (current.second > 0) {
      if (visited[current.first][current.second - 1] == 0) {
        //cout << "L ";
        visited[current.first][current.second - 1] = 1;
        path[current.first][current.second - 1] = 'L';
        bfs.push(make_pair(current.first, current.second - 1));
      }
    }
    if (current.second < m - 1) {
      if (visited[current.first][current.second + 1] == 0) {
        //cout << "R ";
        visited[current.first][current.second + 1] = 1;
        path[current.first][current.second + 1] = 'R';
        bfs.push(make_pair(current.first, current.second + 1));
      }
    }

    //cout << '\n';
  }

  if (possible) {
    while (current != entry){
      fpath.push_back(path[current.first][current.second]);
      if (path[current.first][current.second] == 'U')
        current.first += 1;
      else if (path[current.first][current.second] == 'D')
        current.first -= 1;
      else if (path[current.first][current.second] == 'L')
        current.second += 1;
      else
        current.second -= 1;
    }
    cout << "YES\n" << fpath.size() << '\n';
    while (!fpath.empty()){
      cout << fpath.back();
      fpath.pop_back();
    }
  }
  else
    cout << "NO";
}
