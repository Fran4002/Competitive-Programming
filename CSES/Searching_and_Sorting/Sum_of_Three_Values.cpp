#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define all(x) x.begin(),x.end()
#define range(x,y,z) x.begin()+y,x.begin()+z

typedef long long int ll;
typedef vector<long long int> vi;
typedef vector<pair<long long int, long long int>> pii;

int main() {
  ll n, x, miv, mav, prueba, aux;
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
    //cout << v[i] << " ";
  }
  //cout << '\n';

  //miv = lower_bound(all(v),x - v.back()) - v.begin();
  mav = upper_bound(all(v),x - v.front()) - v.begin();

  //cout <<  "Min iterator: " << miv << "\nMax iterator: " << mav << '\n';

  for (ll i = 0; i < mav; i++) {
    for (ll j = i + 1; j < mav; j++) {
      aux = x - v[i] - v[j];
      if (aux < 1) {
        //cout << "AUX < 1 :"  << x << " - " << v[i] << " - " << v[j] << '\n';
        continue;
      }
      prueba = lower_bound(range(v,i,mav), aux) - v.begin();
      while (prueba == i || prueba == j) {
        //cout << "Prueba = i o j : " << prueba << " " << i << " " << j << '\n';
        prueba++;
      }
      if (prueba >= n) {
        //cout << "Prueba got out scope :" << prueba << '\n';
        continue;
      }
      if (v[i] + v[j] + v[prueba] == x) {
        cout << val[i].second + 1 << " " << val[j].second + 1 << " " << val[prueba].second + 1 << '\n';
        possible = true;
        i = j = mav;
        break;
      }
    }
  }

  if (!possible)
    cout << "IMPOSSIBLE";
}
