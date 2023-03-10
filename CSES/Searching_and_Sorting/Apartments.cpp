#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define all(x) x.begin(), x.end()

int main(){
  long long n, m, k, accomodated = 0;

  cin >> n >> m >> k;

  std::vector<long long> applicants(n), apartments(m);

  for (long long i = 0; i < n; i++) {
    cin >> applicants[i];
  }

  for (long long i = 0; i < m; i++) {
    cin >> apartments[i];
  }

  sort(all(applicants)); sort(all(apartments));

  for (long long i = 0, j = 0; i < n && j < m;){
    if (applicants[i] < apartments[j] - k) {
      i++;
    }
    else if (applicants[i] > apartments[j] + k) {
      j++;
    }
    else{
      accomodated++, i++, j++;
    }
  }

  cout << accomodated;

}
