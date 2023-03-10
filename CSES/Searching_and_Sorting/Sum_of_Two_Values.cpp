#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define all(x) x.begin(),x.end()

typedef long long int ll;
typedef vector<long long int> vi;
typedef vector<pair<long long int, long long int>> pii;

int main() {
  ll n, x, miv, mav, prueba;
  bool possible = false;

  cin >> n >> x;

  pii val(n, make_pair(0,0));
  vi v(n,0);

  for (ll i = 0; i < n; i++) {
    cin >> val[i].first;
    val[i].second = i;
  }

  sort(all(val));

  for (ll i = 0; i < n; i++) {
    v[i] = val[i].first;
  }

  miv = lower_bound(all(v),x - v.back()) - v.begin();
  mav = lower_bound(all(v),x - v.front()) - v.begin();

  //cout <<  "Min iterator: " << miv << "\nMax iterator: " << mav << '\n';

  for (ll i = miv; i <= mav; i++) {
    prueba = lower_bound(all(v),x - v[i]) - v.begin();
    if (prueba == i) prueba++;
    if (prueba >= n) continue;
    if (v[i] + v[prueba] == x) {
      cout << val[i].second + 1 << " " << val[prueba].second + 1 << '\n';
      possible = true;
      break;
    }
  }

  if (!possible)
    cout << "IMPOSSIBLE";
}
