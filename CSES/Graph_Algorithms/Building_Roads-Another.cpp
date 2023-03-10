#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <utility>
using namespace std;
 
#define all(x) x.begin(),x.end()
#define ll long long int
#define vi vector<long long int>

struct dsu{
  vi parent;

  dsu (ll n) {
    parent.resize(n);
    for (ll i = 0; i < n; ++i) {
      parent[i] = i;
    }
  }

  bool merge (ll u, ll v) {
    ll pu = find(u), pv = find(v);

    parent[pu] = pv;

    return (pu == pv);
  }

  ll find(ll x) {

    if (x != parent[x]){
      parent[x] = find(parent[x]);
    }
    
    return parent[x];
  }

  void print() {
    for (auto i : parent){
      cout << i << " ";
    }
    cout << '\n';
  }
};
 
int main(){
  ll n, m, e, s, blocks = 0;
  queue <ll> bfs;
 
  cin >> n >> m;
 
  vi visited(n, 0);
  set <ll> head;
  vector <vi> roads(n,vi());
  dsu nosequehace(n);
 
  for (ll i = 0; i < m; ++i) {
    cin >> e >> s;
    nosequehace.merge(e - 1, s - 1);
  }

  vi v_head;
  
  for (ll i = 0; i < n; ++i) {
    if (i == nosequehace.find(i)) {
      v_head.push_back(i);
    }
  }

  //nosequehace.print();

  cout << v_head.size() - 1 << '\n';


  for (ll i = 1; i < v_head.size(); ++i){
    cout << v_head[i - 1] + 1 << " " << v_head[i] + 1 << '\n';
  }
}