#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

#define all(x) x.begin(), x.end()
//arr[4] = 2 5 3 4
int main(){
  long long n, x, index;
  vector<long long> lis (1);

  cin >> n >> lis[0];


  for (long long i = 1; i < n; i++) {
    cin >> x;

    index = lower_bound(all(lis), x) - lis.begin();

    if (index == 0) {
      lis[0] = x;
    }
    else if (index == lis.size()){
      lis.push_back(x);
    }
    else{
      lis[index] = x;
    }
  }

  //for (int i = 0; i < lis.size(); i++)
    //cout << lis[i] << '\n';

  cout << lis.size();
}
