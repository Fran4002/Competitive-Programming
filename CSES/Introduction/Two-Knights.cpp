#include <iostream>
using namespace std;

int main(){
  int n;
  unsigned long long square, total = 0;

  cin >> n;

  for (int i = 1; i <= n; ++i){
    if (i == 1) cout << 0 << '\n';
    else if (i == 2) cout << 6 << '\n';
    else if (i == 3) cout << 28 << '\n';
    else if (i == 4) cout << 96 << '\n';
    else{
      square = i * i;
      total = 0;

      total += 4 * (square - 3); //Edge
      total += 8 * (square - 4); //Edge adyacent
      total += 4 * (i - 4) * (square - 5); //True border
      total += 4 * (square - 5); //Second square Edge
      total += 4 * (i - 4) * (square - 7);
      total += (i - 4) * (i - 4) * (square - 9);

      cout << total / 2 << '\n';
    }
  }
}
