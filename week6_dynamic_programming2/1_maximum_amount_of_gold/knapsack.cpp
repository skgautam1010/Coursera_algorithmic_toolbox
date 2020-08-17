#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using namespace std;
int optimal_weight(int W, const vector<int> &w) {
  int n=w.size();
  vector<vector<int> >value(n+1,vector<int>(W+1));
  for(int i=0;i<=n;i++)
  {
    value[i][0]=0;
  }
  for(int j=0;j<=W;j++)
  {
    value[0][j]=0;
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=W;j++)
    {
      if(w[i-1]>j)
      {
        value[i][j]=value[i-1][j];
      }
      else
      {
        value[i][j]=std::max(w[i-1]+value[i-1][j-w[i-1]],value[i-1][j]);
      }
      
    }
  }
  int result = value[n][W];

  return result;

}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
