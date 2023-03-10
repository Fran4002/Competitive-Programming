#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n;
vector<vector<long long>> paths;
vector<vector<bool>> visted;
vector<vector<char>> grid;

long long func(int x, int y){
  if (x >= n || y >= n)
    return 0;
  if (grid[x][y] == '*')
    return 0;
  else if (visted[x][y])
    return paths[x][y];
  else if (x == n - 1 && y == n - 1)
    return 1;
  else{
    visted[x][y] = true;
    paths[x][y] = (func(x + 1, y) + func(x, y + 1)) % 1000000007;
    return paths[x][y];
  }
}

int main(){

  cin >> n;

  std::vector<long long> aui(n, 0);
  std::vector<char> auc(n,'.');
  std::vector<bool> aub(n, 0);

  for (long long i = 0; i < n; i++) {
    /* code */
    paths.push_back(aui);
    grid.push_back(auc);
    visted.push_back(aub);

    for (long long j = 0; j < n; j++) {
      /* code */
      cin >> grid.back()[j];
    }
  }
  /*
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      cout << grid[i][j];
    }
  }
  */

  cout << func(0, 0);

}
