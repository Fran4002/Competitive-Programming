#include <iostream>
using namespace std;

int main(){
  long long t, x, y;
  cin >> t;

  while (t){
    --t;
    cin >> y >> x;
    if (x == y){
      cout << x * y - x + 1 << '\n';
    }
    else if (x > y){
      if (x % 2){
        cout << x * x - y + 1 << '\n';
      }
      else{
        cout << (x - 1) * (x - 1) + y << '\n';
      }
    }
    else{
      if (y % 2){
        cout << (y - 1) * (y - 1) + x << '\n';
      }
      else{
        cout << y * y - x + 1 << '\n';
      }
    }
  }
}
