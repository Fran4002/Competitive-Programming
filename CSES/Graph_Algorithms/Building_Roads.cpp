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
  ll n, m, e, s, blocks = 0;
  queue <ll> bfs;

  cin >> n >> m;

  vi visited(n, 0), head;
  vector <vi> roads(n,vi());

  for (ll i = 0; i < m; ++i) {
    cin >> e >> s;
    roads[e - 1].push_back(s - 1);
    roads[s - 1].push_back(e - 1);
  }

  for (ll i = 0; i < n; ++i) {
    if (visited[i] == 0){
      bfs.push(i);
      head.push_back(i);
      blocks++;
    }

    while (!bfs.empty()){
      e = bfs.front(); bfs.pop();
      for (ll j = 0; j < roads[e].size(); ++j) {
        if (visited[roads[e][j]] == 0)
          bfs.push(roads[e][j]);
        visited[roads[e][j]] = 1;
      }
    }
  }

  cout << blocks - 1;
  if (head.size()) for (ll i = 1; i < head.size(); ++i)
    cout << '\n' << head[i] + 1 << " " << head[i - 1] + 1;

}
