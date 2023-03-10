#include <iostream>
#include <vector>
using namespace std;

long long ans(long long n, int digit){
  vector <int> digits;
  long long aux = n;

  while (aux > 0){
    digits.push_back(aux % 10);
    aux /= 10;
  }

  return digits[digits.size() - digit];

}

int QoD(long long n){
  int d = 0;

  if (n == 0) return 1;

  while (n){
    n /= 10;
    d++;
  }

  return d;
}


int main(){
  long long q, k, num;
  int step;

  cin >> q;

  while (q){
    --q, step = 1;
    cin >> k;

    for (num = 1; step < k; k -= step, num++){
      //cout << num << '\t' << step << '\t' << k << '\n';=
      if (num % 10 == 0)
        step = QoD(num);
    }

    cout << ans(num, k) << '\n';
  }
}
