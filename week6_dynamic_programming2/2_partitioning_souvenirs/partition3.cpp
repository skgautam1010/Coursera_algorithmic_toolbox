#include <iostream>
#include <vector>

using std::vector;

int partition3(vector<long long int> &A) {
  int sum=0;
  int n=A.size();
  for(int i=0;i<A.size();i++)
  {
    sum =sum+A[i];
  }
  long long int subset=sum/3;
  vector<vector<long long int>> partition((n+1),vector<long long int>(subset+1));
  if(sum%3!=0)
  {
    return 0;
  }
  if(n<3)
  {
    return 0;
  }
  if(sum%3==0)
  {
    for(int i=0;i<=n;i++)
    {
      partition[i][0]=1;
    }
    for(int j=1;j<=subset;j++)
    {
      partition[0][j]=0;
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=subset;j++)
      {
        if(A[i-1]>j)
        {
          partition[i][j]=partition[i-1][j];
        }
        else
        {
          partition[i][j]=((partition[i-1][j-A[i-1]])|| (partition[i-1][j]));
        }
        
      }
    }
    int result=partition[n][subset];
    return result;

  }
  

}

int main() {
  int n;
  std::cin >> n;
  vector<long long int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
