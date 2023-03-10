#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  long long n, x;
  vector<long long> v;

  cin >> n;
  for (long i = 1; i < n; i++){
    cin >> x;
    v.push_back(x);
  }

  sort(v.begin(), v.end());

  for (long i = 0; i <= n; i++){
    if (v[i] != i + 1){
      cout << i + 1;
      break;
    }
  }
}
