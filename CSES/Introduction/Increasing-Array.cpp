#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long n, x, minimum = 0;
  vector<long long> v;

  cin >> n;
  for (long i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }

  for (long i = 1; i < n; i++) {
    if (v[i] < v[i - 1]) {
      minimum += v[i - 1] - v[i];
      v[i] = v[i - 1];
    }
  }

  cout << minimum;
}
