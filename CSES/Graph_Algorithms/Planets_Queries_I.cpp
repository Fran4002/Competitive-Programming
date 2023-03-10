#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define all(x) x.begin(), x.end()

typedef long long int ll;
typedef vector<long long int> vi;

ll n, q;
vi teleport, visited;
vector <vi> cycles;

void entry() {
    cin >> n >> q;

    teleport.resize (n + 1);
    cycles.resize(n + 1, vi());

    for (ll i = 1; i <= n; i++) {
      cin >> teleport[i];
      cycles[i].push_back(teleport[i]);
    }
}

void processing () {
  bool flag = true;
  for (ll k = 0; k < n; k++) {
    flag = false;
    for (ll i = 1; i <= n; i++) {
      if (teleport[cycles[i].back()] == i) continue;

      cycles[i].push_back(teleport[cycles[i].back()]);
      flag = true;
    }

    if (!flag) break;
  }
}

void solve() {
  ll x, k;

  cin >> x >> k;

  k %= (cycles[x].size() + 1);

  if (k == 0) {
    cout << x;
  }
  else {
    cout << cycles[x][k];
  }
}


int main() {
  entry();
  processing();

  while (t--) {
    solve();
  }
}
