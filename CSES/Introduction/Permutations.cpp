#include <iostream>
using namespace std;

int main(){
  long long n;

  cin >> n;

  if (n == 1) cout << 1;
  else if (n <= 3) cout << "NO SOLUTION";
  else{
    if (n % 2){
      for (long long i = n; i > 0; i -= 2) cout << i << '\t';
      for (long long i = n - 1; i > 0; i -= 2) cout << i << '\t';
    }
    else{
      for (long long i = n - 1; i > 0; i -= 2) cout << i << '\t';
      for (long long i = n; i > 0; i -= 2) cout << i << '\t';
    }
  }
}
