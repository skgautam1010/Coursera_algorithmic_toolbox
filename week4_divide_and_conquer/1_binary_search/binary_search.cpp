#include <iostream>
#include <cassert>
#include <vector>
#include <math.h>

using std::vector;

long long int binary_search(const vector<long long int> &a, long long int x) {
  long long int left = 0, right = (long long int)a.size(); 
  long long int mid;
  
    while (left<=right)
    {
      mid=(right-left)/2+left;
      if(a[mid]==x)
      {
        return mid;
      }
      if (x>a[mid])
      {
        left=mid+1;
      }
      else
      {
        right=mid-1;
      }
      
      
    }
    return -1;
  
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  long long int n;
  std::cin >> n;
  vector<long long int> a(n);
  for (long long int i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  long long int m;
  std::cin >> m;
  vector<long long int> b(m);
  for (long long int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (long long int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
