#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

#define all(x) x.begin(),x.end()

long long n, x;
vector <pair<long long, long long>> books;

long long dp(long long cash, long long book, long long pages){
  if (book >= n)
    return pages;
  else if (cash >= books[book].first)
    return max(dp(cash - books[book].first, book + 1, pages + books[book].second), dp(cash, book + 1, pages));
  else
    return pages;
}


int main(){
  long long aux;

  cin >> n >> x;

  for (long long i = 0; i < n; i++){
    cin >> aux;
    books.push_back(make_pair(aux, 0));
  }

  for (long long i = 0; i < n; i++){
    cin >> books[i].second;
    //books.push_back(make_pair(aux, 0));
  }

  sort(all(books));

  cout << dp(x, 0, 0);
}
