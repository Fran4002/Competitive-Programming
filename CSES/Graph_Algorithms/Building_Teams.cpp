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
  ll n, m, e, s;
  queue <ll> bfs;
  bool possible = true;

  cin >> n >> m;

  vi visited(n, 0), team(n, 0);
  vector <vi> friendships(n,vi());

  for (ll i = 0; i < m; ++i) {
    cin >> e >> s;
    friendships[e - 1].push_back(s - 1);
    friendships[s - 1].push_back(e - 1);
  }
/*
  for (ll i = 0; i < n; ++i) {
    cout << "#" << i << '\n';
    for (ll j = 0; j < friendships[i].size(); j++)
      cout << friendships[i][j] << " "; cout << '\n';
  }
*/
  for (ll i = 0; i < n; ++i) {
    if (visited[i] == 0){
      bfs.push(i);
      team[i] = 1;
      visited[i] = 1;
    }

    while (!bfs.empty()){
      e = bfs.front(); bfs.pop();
      for (ll j = 0; j < friendships[e].size(); ++j) {
        //cout << e << " " << friendships[e][j] << '\n';
        if (visited[friendships[e][j]] == 0){
          if (team[e] == 1){
            team[friendships[e][j]] = 2;
          }
          else {
            team[friendships[e][j]] = 1;
          }
          bfs.push(friendships[e][j]);
        }
        else if (team[e] == team[friendships[e][j]]) {
          //cout << "Equal teams: " << e << " " << friendships[e][j] << '\n';
          i = n;
          possible = false;
          break;
        }
        visited[friendships[e][j]] = 1;
      }
    }

    //for (ll j = 0; j < n; j++) cout << visited[j] << " "; cout << '\n';
  }

  if (possible)
    for (ll i = 0; i < n; i++)
      cout << team[i] << " ";
  else
    cout << "IMPOSSIBLE";

}
