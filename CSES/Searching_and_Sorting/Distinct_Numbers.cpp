#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
  set <long long> s;
  long long n, x;

  cin >> n;

  for (long long i = 0; i < n; i++){
    cin >> x;
    s.insert(x);
  }

  cout << s.size();
}
