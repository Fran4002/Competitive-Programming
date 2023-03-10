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
  string str;
  vector <string> strs;

  cin >> str;

  sort(all(str));

  do {
    strs.push_back(str);
  } while (next_permutation(str.begin(), str.end()));

  cout << strs.size();
  for (auto e: strs){
    cout << '\n' << e;
  }
}
