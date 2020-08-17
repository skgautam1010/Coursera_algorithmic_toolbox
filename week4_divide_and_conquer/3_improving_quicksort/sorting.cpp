#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;


int partition3(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  /*if (l >= r) {
    return;
  }*/
  while (l<r)
  {
    int m=partition3(a,l,r);
    if(m-l<r-m)
    {
      randomized_quick_sort(a,l,m-1);
      l=m+1;
    }
    else
    {
      randomized_quick_sort(a,m+1,r);
      r=m-1;
    }
    
  }
  
  /*int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m1,m2;
  m1 = partition3(a, l, r);

  randomized_quick_sort(a, l, m1 - 1);
  randomized_quick_sort(a, m2 + 1, r);
}*/
}
int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
