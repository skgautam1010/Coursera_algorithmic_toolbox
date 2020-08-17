#include <iostream>
using namespace std;
long long int gcd_naive(int a,int b)
{
  if(b==0)
  {
    return a;
  }
  else
  {
    int a1=a%b;
    return gcd_naive(b,a1);
  }
  
}

long long lcm_naive(int a, int b) {
  long long int lcm=(long long)a*b/gcd_naive(a,b);

  return lcm;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
