#include <iostream>
#include <vector>
using namespace std;

bool check(vector <bool> v){
  for (int i = 0; i < v.size(); ++i)
    if (v[i] == false) return false;
  return true;
}

int main(){
  int n; bool a;

  cin >> n;

  vector <bool> code(n, 0), flag(n, 0);

  while(!check(flag)){
    for (int i = 0; i < n; ++i)
      cout << code[i]; cout << '\n';


    for (int i = 0; i < n; i++){
      if (flag[i] == false){
        code[i] = !code[i];
        for (int j = 0; j < i; ++j)
          flag[j] = false;
        flag[i] = true;
        break;
      }
    }
  }

  for (int i = 0; i < n; ++i)
      cout << code[i]; cout << '\n';
}
