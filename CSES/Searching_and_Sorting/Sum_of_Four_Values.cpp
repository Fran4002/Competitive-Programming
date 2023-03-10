#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

#define all(x) x.begin(),x.end()

typedef long long int ll;
typedef vector<long long int> vi;
typedef vector<pair<long long int, long long int>> pii;

vector<pair<ll,pair<ll,ll>>> merged;
ll n, x, miv, mav, prueba;
vi sorted;

bool difpair(pair<ll,ll> a, pair<ll,ll> b) {
  if (a.first == b.first) return false;
  else if (a.first == b.second) return false;
  else if (a.second == b.first) return false;
  else if (a.second == b.second) return false;
  else return true;
}

bool checkIn(ll u, ll v) {
  ll maxin = upper_bound(all(sorted),x - sorted[u]) - sorted.begin();

  for (ll i = v; i < maxin; i++) {
    if (difpair(merged[u].second, merged[v].second)) {
      //cout << "They diffeteny";
      cout << merged[u].second.first + 1 << " " << merged[u].second.second + 1 << " " << merged[v].second.first + 1 << " " << merged[v].second.second + 1 << '\n';
      return true;
    }
  }
  //cout << " They dont work\n";
  return false;
}

void printmerge() {
  cout << '\n';

  for (ll i = 0; i < merged.size(); ++i) {
    cout << i << " ";
    if (i < 10) cout << " ";
  }


  cout << '\n';

  for (ll i = 0; i < merged.size(); ++i) {
    cout << merged[i].first << " ";
    if (merged[i].first < 10) cout << " ";
  }

  cout << '\n';

  for (ll i = 0; i < merged.size(); ++i) {
    cout << merged[i].second.first << " ";
    if (merged[i].second.first < 10) cout << " ";
  }

  cout << '\n';

  for (ll i = 0; i < merged.size(); ++i) {
    cout << merged[i].second.second << " ";
    if (merged[i].second.second < 10) cout << " ";
  }

  cout << '\n';
}

int main() {
  bool possible = false;

  cin >> n >> x;

  vi values(n);

  for (ll i = 0; i < n; i++) {
    cin >> values[i];
  }

  for (ll i = 0; i < n; i++) {
    for (ll j = i + 1; j < n; j++) {
      merged.push_back(make_pair(values[i] + values[j], make_pair(i, j)));
    }
  }

  /*
  for (ll i = 0; i < merged.size(); i++) {
    cout << merged[i].first << " " << merged[i].second.first << " " << merged[i].second.second << '\n';
  }
  */

  sort(all(merged));

  sorted.resize(merged.size());

  for (ll i = 0; i < merged.size(); ++i) {
    sorted[i] = merged[i].first;
  }

  //printmerge();

  //miv = lower_bound(all(sorted),x - sorted.back()) - sorted.begin();
  //mav = lower_bound(all(sorted),x - sorted.front()) - sorted.begin();

  for (ll i = 0; i < merged.size(); i++) {
    prueba = lower_bound(all(sorted),x - sorted[i]) - sorted.begin();

    if (prueba == i) prueba++;
    if (prueba >= merged.size()) continue;

    if (sorted[i] + sorted[prueba] == x) {
      //cout << "Suman: " << i << " " << prueba;
      if (checkIn(i, prueba)) {
        possible = true;
        break;
      }
      else continue;
    }
    else {
      //cout << sorted[i] + sorted[prueba] << '\n';
    }
  }

  if (!possible)
    cout << "IMPOSSIBLE\n";
}
