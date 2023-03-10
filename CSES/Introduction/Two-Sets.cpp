#include <iostream>
using namespace std;

int main(){
  long long n, k;

  cin >> n;

  if (n % 4 == 0){
    cout << "YES" << '\n';
    k = n / 4;

    cout << 2 * k << '\n';
    for (long long i = k + 1; i <= 3 * k; ++i)
      cout << i << '\t'; cout << '\n';

    cout << 2 * k << '\n';
    for (long long i = 1; i <= k; ++i)
      cout << i << '\t';
    for (long long i = 3 * k + 1; i <= 4 * k; ++i)
      cout << i << '\t'; cout << '\n';

  }
  else if (n % 4 == 3){
   cout << "YES" << '\n';
    k = (n + 1) / 4;

    cout << 2 * k << '\n';
    for (long long i = k; i <= 3 * k - 1; ++i)
      cout << i << '\t'; cout << '\n';

    cout << 2 * k - 1 << '\n';
    for (long long i = 1; i <= k - 1; ++i)
      cout << i << '\t';
    for (long long i = 3 * k; i <= 4 * k - 1; ++i)
      cout << i << '\t'; cout << '\n';

  }
  else cout << "NO";
}
