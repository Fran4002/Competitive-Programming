#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(),x.end()
#define readv(x) for (auto &v: x) cin >> v;
#define printv(x) for (auto &v: x) cout << v << " ";

using ll = long long int;
using ull = unsigned long long int;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vc = vector<char>;

const ll MOD = 1e9 + 7;

void solve () {
  ll n;
  vector<vc> board;
  vector<vll> mat;

  cin >> n;
  board.resize(n, vc(n)); 
  mat.resize(n, vll(n, 0));

  for (vc &row: board) {
    for (char &c: row) cin >> c;
  }

  mat[0][0] = 1;

  if (board.back().back() == '*') {
    cout << 0 << '\n';
    return;
  }

  queue<pll> q;
  q.push({0, 0});

  while (!q.empty()) {
    const pll p = q.front(); q.pop();

    if (board[p.first][p.second] == '*') continue;
    board[p.first][p.second] = '*';

    if (p.first + 1 < n) {
      q.push({p.first + 1, p.second});
      mat[p.first + 1][p.second] += mat[p.first][p.second];
      mat[p.first + 1][p.second] %= MOD;
    }

    if (p.second + 1 < n) {
      q.push({p.first, p.second + 1});
      mat[p.first][p.second + 1] += mat[p.first][p.second];
      mat[p.first][p.second + 1] %= MOD;
    }
  }

  cout << mat[n - 1][n - 1] << '\n';
}

int main () {
  //cin.tie(0) -> ios_base::sync_with_stdio(0);

  int t = 1;

  //cin >> t;

  for (int i = 1; i <= t; i++) {
    //cout << "Test #" << i << ":\n";
    solve();
  }
}
