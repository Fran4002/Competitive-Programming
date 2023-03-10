#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
  vector <long long> alphabet(26, 0);
  bool bandera = false, posible = true;
  string str;
  char extra = char(0);

  cin >> str;

  for (long long i = 0; i < str.size(); ++i){
    alphabet[int(str[i]) - int('A')]++;
  }

  for (int i = 0; i < alphabet.size(); ++i){
    if (alphabet[i] % 2){
      if (bandera){
        posible = false;
        break;
      }
      alphabet[i]--;
      bandera = true;
      extra = char(int('A') + i);
    }
  }


  if (posible){
    for (int i = 0; i < alphabet.size(); ++i){
      for (long long j = 0; j < alphabet[i] / 2; ++j){
        cout << char(int('A') + i);
      }
    }

    if (extra) cout << extra;

    for (int i = alphabet.size() - 1; i >= 0; --i){
      for (long long j = 0; j < alphabet[i] / 2; ++j){
        cout << char(int('A') + i);
      }
    }
  }
  else
    cout << "NO SOLUTION";
}
