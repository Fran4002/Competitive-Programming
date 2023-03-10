#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

#define all(x) x.begin(), x.end()
typedef long long int ll;
typedef vector<long long int> vi;

vector <vi> edges;
vi idk, path;
ll aux, n;
bool possible = false;

ll bfs(ll x) {
  if (x == n - 1){
    possible = true;
    return 1;
  }
  else if (idk[x] != 0) {
    //cout << x << " = " << idk[x] << '\n';
    return idk[x];
  }
  else if (edges[x].size() == 0){
    idk[x] = -2000;
    //cout << x << " has no children\n";
    return idk[x];
  }
  else {
    //cout << "Processing " << x << '\n';

    idk[x] = 1 + bfs(edges[x][0]);
    path[x] = edges[x][0];

    //cout << "Pregunta: " << x << " = " << idk[x] << '\n';

    for (ll i = 1; i < edges[x].size(); ++i) {
      aux = bfs(edges[x][i]) + 1;
      if (aux > idk[x]) {
        idk[x] = aux;
        path[x] = edges[x][i];
        //cout << "Cambio: " << x << " = " << idk[x] << '\n';
      }
    }

    return idk[x];
  }
}

int main() {
  ll m, a, b, answer;

  cin >> n >> m;

  edges = vector<vi>(n,vi());
  idk = vi(n, 0);
  path = vi(n, 0);

  for (ll i = 0; i < m; i++) {
    cin >> a >> b;
    edges[a - 1].push_back(b - 1);
  }

  /*for (ll i = 0; i < n; i++) {
    cout << i << "#\n";
    for (ll j = 0; j < edges[i].size(); j++) {
      cout << edges[i][j] << " ";
    }
    cout << '\n';
  }*/

  answer = bfs(0);

   if (possible) {
     cout << answer << '\n';

     aux = 0;

     while (aux != n - 1) {
       cout << aux + 1 << " ";
       aux = path[aux];
     }

     cout << n;
   }
   else {
     cout << "IMPOSSIBLE\n";
   }

}

/*
5 5
1 2
2 5
1 3
3 4
4 5
*/
