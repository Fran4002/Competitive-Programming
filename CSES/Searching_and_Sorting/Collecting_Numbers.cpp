#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define all(x) x.begin(),x.end()

typedef long long int ll;
typedef vector<long long int> vi;

int main() {
  ll n, cont = 1, num = 1;
  bool change;

  cin >> n;

  vi numbers(n, 0);

  for (ll i = 0; num <= n; i++) {
    if (i >= n) {
      cont++;
      i %= n;
    }
    if (num == numbers[i]) num++;
  }

  cout << cont;
}
