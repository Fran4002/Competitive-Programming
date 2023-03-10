#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define all(x) x.begin(),x.end()
#define ll long long int

vector <ll> visited;

void solve(){
  ll a, b, pot = 1, count = 0;
  visited.clear();
  visited = vector <ll> (1000000007, 0);

  cin >> a >> b;

  a %= 1000000007;

  while (visited[pot] == 0 && b--) {
    count++;
    visited[pot] = count;
    pot = (pot * a) % 1000000007;
  }

  if (b){
    b %= (count + 1 - visited[pot]);
    while (b--) {
      pot = (pot * a) % 1000000007;
    }
  }


  cout << pot << '\n';
}

int main(){
  ll t = 1;

  cin >> t;

  while (t--) {
    solve();
  }
}
