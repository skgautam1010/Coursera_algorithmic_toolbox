#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using namespace std;
void merge(vector<long long int>&a,long long int l,long long int m,long long int r)
{
  int i,j,k;
  int n1=m-l+1;
  int n2=r-m;
  int L[n1],R[n2];
  for(i=0;i<n1;i++)
  {
    L[i]=a[l+i];
  }
  for(j=0;j<n2;j++)
  {
    R[j]=a[m+1+j];
  }
  i=0;j=0;k=l;
  while(i<n1 && j<n2)
  {
    if(L[i]<R[j])
    {
      a[k]=L[i];
      i++;
    }
    else
    {
      a[k]=R[j];
      j++;
    }
    k++;
    
  }
  while(i<n1)
  {
    a[k]=L[i];
    k++;
    i++;
  }
  while(j<n2)
  {
    a[k]=R[j];
    j++;k++;
  }

}
void merge_sort(vector<long long int>&a,long long int l,long long int r)
{
  if(l<r)
  {
    int mid=l+(r-l)/2;
    merge_sort(a,l,mid);
    merge_sort(a,mid+1,r);
    merge(a,l,mid,r);
  }

}

int get_majority_element(vector<long long int> &a, long long int left, long long int right) {
 if (left == right) return -1;
  if (left + 1 == right) return a[left];
  int count=1;
  int m=right/2;
  int temp=a[0];
  int max_ele=-1;
  int f=0;
  merge_sort(a,left,right);
  for(int i=1;i<right;i++)
  {
    if(temp==a[i])
    {
      count++;
    }
    else
    {
      count=1;
      temp=a[i];
    }
    if(count>max_ele)
    {
      max_ele=count;
      if(max_ele>m)
      {
        f=1;
        break;
      }
    }
    
  }
  return (f==1 ? 1 : -1);
  
} 

int main() {
  
  int n;
  std::cin >> n;
  vector<long long int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
