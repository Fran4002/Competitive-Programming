#include <iostream>
#include <string>
using namespace std;

int main(){
  string str;
  char c = 'x'; long long lgst = 0, actual = 0;
  cin >> str;

  for (long long i = 0; i < str.size(); i++){
    if (c != str[i]){
      c = str[i];
      if (actual > lgst) lgst = actual;
      actual = 1;
    }
    else actual++;
  }

  if (actual > lgst) lgst = actual;
 
  cout << lgst;
}
