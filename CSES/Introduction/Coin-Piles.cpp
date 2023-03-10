#include <iostream>
using namespace std;

int main(){
  long long t, a, b;

  cin >> t;

  while (t){
    --t;
    cin >> a >> b;

    if ((a + b) % 3 == 0){
      if (a < b) swap(a, b);
      if (a > 2 * b) cout << "NO\n";
      else cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }
  }
}
